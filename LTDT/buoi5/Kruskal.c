#include<stdio.h>

//Graph
typedef struct{
    int u, v;
    int w;
}Edge;

typedef struct {
    int n, m;
    Edge edges[100];
}Graph;
void init_graph(Graph* G, int n){
    G->n = n;
    G->m = 0;
}
void add_edge(Graph *G, int u, int v, int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

void Swap(Edge *a, Edge *b){
    Edge temp;
    temp =  *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(Graph *G, int n){
    int i, j;
    for(i = 0; i <= n; i++)
        for(j = i+1; j <= n; j++){
            if(G->edges[i].w < G->edges[j].w)
                Swap(&G->edges[i], &G->edges[j]);
        }
}

int parent[100];
int findRoot(int u){
    if(parent[u] == u)
        return u;
    return findRoot(parent[u]);
}

int Kruskal(Graph* G, Graph* T){
    BubbleSort(G,G->n);
    init_graph(T,G->n);
    int u;
    for(u = 1; u <= G->m; u++)
        parent[u] = u;
    int sum_w = 0;
    int e;
    for(e = 1; e <= G->m; e++){
        int u = G->edges[e].u;
        int v = G->edges[e].v;
        int w = G->edges[e].w;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if(root_u != root_v){
            if(u < v)
                add_edge(T,u,v,w);
            else
                add_edge(T,v,u,w);
            parent[root_v] = root_u;
            sum_w += w;
        }
    }
    return sum_w;
}

int main(){
    Graph G, T;
    int n, m, u, v, w, e;
    FILE *f = freopen("Kruskal.txt", "r", stdin);
    scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
    int sum_w = Kruskal(&G, &T);
    printf("Tong trong so cua cay T la : %d\n", sum_w);
    for(e = T.m-1; e >= 0; e--)
            printf("(%d, %d): %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
    return 0;
}