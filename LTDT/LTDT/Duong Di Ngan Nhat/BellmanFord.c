#include<stdio.h>
#define MAX_N 20
#define oo 999999
/*---------------------------------Graph-------------------------------*/

//Khai bao cau truc do thi
typedef struct{
	int u, v;
	int w;
}Edge;

typedef struct{
	int n, m;
	Edge edges[MAX_N];
}Graph;

//Khoi tao do thi
void init_Graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

//Them 1 cung vao do thi
void add_edges(Graph *G, int u, int v, int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m = G->m + 1;
}

/*---------------------------------Bellman-Ford-------------------------------*/
int pi[MAX_N];
int p[MAX_N];

void BellmanFord(Graph *G, int s){
	int u, v, w, it, k;
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	
	//Lap n-1 lan
	for(it = 1; it < G->n; it++){
		//Duyet qua cac cung va cap nhat neu co
		for(k = 0; k < G->m; k++){
			u = G->edges[k].u;
			v = G->edges[k].v;
			w = G->edges[k].w;
			if(pi[u] == oo){ //Chua co duong di den u bo qua cung (u, v)
				continue;
			}
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}
int main(){
	Graph G;
	//freopen("dothi1.txt","r",stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v, w;
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edges(&G, u, v, w);
	}
	BellmanFord(&G, 1);
	for(e = 1; e <= n; e++){
		printf("pi[%d] = %d, p[%d] = %d\n", e, pi[e], e, p[e]);
	}
	return 0;
}
