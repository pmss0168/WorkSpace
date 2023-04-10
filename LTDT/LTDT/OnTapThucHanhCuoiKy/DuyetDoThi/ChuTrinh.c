#include<stdio.h>
#define MaxN 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

/*----------------------------------Graph----------------------------------*/

typedef struct{
	int A[MaxN][MaxN];
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

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
	G->A[v][u] = 1;
}

int adjacent(Graph *G, int u, int v){
	return G->A[u][v] != 0;
}

/*----------------------------------/Graph----------------------------------*/


/*----------------------------------Circle----------------------------------*/

int color[MaxN];
int has_circle = 0;

void ChuTrinh(Graph *G, int u, int p){
	color[u] = GRAY;
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G, u, v)){
			if(v == p){
				continue;
			}
			else if(color[v] == WHITE){
				ChuTrinh(G, v, u);
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
	freopen("dt.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= n; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i;
	for(i = 1; i <= n; i++){
		color[i] = WHITE;
	}
	for(i = 1; i <= n; i++){
		if(color[i] == WHITE){
			ChuTrinh(&G, i, -1);
		}
	}
	if(has_circle == 1) printf("YES");
	else printf("NO");
	return 0;
}



