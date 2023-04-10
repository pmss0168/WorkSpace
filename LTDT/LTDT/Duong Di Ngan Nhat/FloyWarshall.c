#include<stdio.h>
#define MAX_N 100
#define NO_EDGE 0
#define oo 999999
/*-----------------Graph-----------------*/

//khai bao cau truc Graph
typedef struct{
	int W[MAX_N][MAX_N];
	int n;
}Graph;

//khoi tao do thi n dinh, 0 cung
void init_Graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->W[i][j] = NO_EDGE;
		}
	}
}

//them cung va trong so
void add_edges(Graph *G, int u, int v, int  w){
	G->W[u][v] = w;
}

//thuat toan Floyd-Warshall
int pi[MAX_N][MAX_N];
int next[MAX_N][MAX_N];
void FloydWarshall(Graph *G){
	int u, v, k;
	for(u = 1; u <= G->n; u++){
		for(v = 1; v <= G->n; v++){
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	}
	for(u = 1; u <= G->n; u++){
		pi[u][u] = 0;
	}
	for(u = 1; u <= G->n; u++){
		for(v = 1; v <= G->n; v++){
			if(G->W[u][v] != NO_EDGE){
				pi[u][v] = G->W[u][v]; //di truc tiep tu u -> v
				next[u][v] = v;
			}
		}
	}
	for(k = 1; k <= G->n; k++){
		for(u = 1; u <= G->n; u++){
			for(v = 1; v <= G->n; v++){
				if(pi[u][k] + pi[k][v] < pi[u][v]){
					pi[u][k] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
	}
}
int main(){
	Graph G;
	freopen("dothi2.txt","r",stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v, w;
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edges(&G, u, v, w);
	}
	FloydWarshall(&G);
	for(u = 1; u <= n; u++){
		for(v = 1;  v <= n; v++){
			printf("%d -> %d: %d\n", u, v, pi[u][v]);
		}
	}
	return 0;
}














