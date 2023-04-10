#include<stdio.h>
#define MAXN 100
#define NO_EDGE 0
#define oo 999999

typedef struct{
	int W[MAXN][MAXN];
	int n;
}Graph;

void init_Graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->W[i][j] = NO_EDGE;
		}
	}
}

void add_edge(Graph *G, int u, int v, int w){
	G->W[u][v] = w;
}

int mark[MAXN], pi[MAXN], p[MAXN];

void MooreDijkstra(Graph *G, int s){
	int it, u, v;
	
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
		mark[u] = 0;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it < G->n; it++){
		int j, min_pi;
		
		for(j = 1; j <= G->n; j++){
			if(mark[j] == 0 && pi[j] < min_pi){
				min_pi = pi[j];
				u = j;
			}
		}
		
		mark[u] = 1;
		
		for(v = 1; v <= G->n; v++){
			if(G->W[u][v] != NO_EDGE && mark[v] == 0){
				if(pi[u] + G->W[u][v] < pi[v]){
					pi[v] = pi[u] + G->W[u][v];
					p[v] = u;
				}
			}
		}	
	}
}

int main(){
	Graph G;
	int n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v, w;
	for(e = 1; e <= m ;e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	MooreDijkstra(&G, 1);
	int i;
	for(i = 1; i <= n; i++){
		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
	}
	return 0;
}







