#include<stdio.h>
#define Max_G 50
#define Max_Q 50
#define Max_L 50

/* --------------------------------------Start Graph-------------------------------------- */

typedef struct{
	int A[Max_G][Max_G];
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

/* --------------------------------------End Graph-------------------------------------- */

/*------------------------------------------Start main------------------------------------------*/

int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	return 0;
}

/*------------------------------------------End main------------------------------------------*/
