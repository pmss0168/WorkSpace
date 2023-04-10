#include<stdio.h>
#define MAX_N 20
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
    int A[MAX_N][MAX_N];
    int n;
}Graph;

void init_Graph(Graph *G, int n){
    G->n = n;
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            G->A[i][j] = 0;
        }
    }
}


void add_edges(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->A[v][u] = 1;
}

int adjacent(Graph *G, int u, int v){
    if(G->A[u][v] != 0 || G->A[v][u] != 0){
        return 1;
    }
    return 0;
}

int color[MAX_N];
int has_circle = 0;

void DFS(Graph *G, int u, int p){
    
    //1. To mau cho dinh u dang duyet
    color[u] = GRAY;
    
    //2. Xet cac dinh ke cua u
    int v;
    for(v = 1; v <= G->n; v++){
        if(adjacent(G, u, v)){
            if(v == p){
                continue;
            }
            if(color[v] == WHITE){
                DFS(G, v, u);
            }
            else if(color[v] == GRAY){
                has_circle = 1;
            }
        }
    }
    color[u] = BLACK;
}

int main(){
    Graph G;
    int n, m;
    freopen("dothi.txt","r",stdin);
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    int e, u, v;
    for(e = 1; e <= n; e++){
        scanf("%d%d", &u, &v);
        add_edges(&G, u, v);
    }
    for(v = 1; v <= n; v++){
        color[v] = WHITE;
    }
    for(u = 1; u <= n; u++){
        if(color[u] == WHITE){
            DFS(&G, u, -1);
        }
    }
    if(has_circle == 1) printf("YES");
    else printf("NO");
    return 0;
}
