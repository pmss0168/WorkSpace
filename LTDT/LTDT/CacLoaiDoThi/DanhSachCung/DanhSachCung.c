#include<stdio.h>
#define Max_V 50
#define Max_E 50

/*------------------------------------------Start Graph------------------------------------------*/

typedef struct{
	int u, v;
}Edge;

typedef struct{
	int n, m;
	Edge edges[Max_E];
}Graph;

void init_Graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int u, int v){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->m = G->m + 1;
}

/*------------------------------------------End Graph------------------------------------------*/

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
