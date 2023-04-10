#include<stdio.h>
#define MAX_N 50
#define oo 999999
#define NO_EDGE 0

/*----------------------------Graph----------------------------*/

typedef struct{
	int n;
	int A[MAX_N][MAX_N];
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

void add_edge(Graph *G, int u, int v, int w){
	G->A[u][v] = w;
}

/*----------------------------Prim----------------------------*/

int pi[MAX_N];
int p[MAX_N];
int mark[MAX_N];

int Prim(Graph *G, Graph *pT, int s){
	int i, u, v, x;
	
	//1.Khoi tao
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
		p[u] = -1;
		mark[u] = 0;
	}
	pi[s] = 0;
	
	//2.Lap n-1 lan
	for(i = 1; i < G->n; i++){
		//2a.Tim u gan voi S nhat (tim u co pi[u] nho nhat)
		int min_dist = oo;
		for(x = 1; x <= G->n; x++){
			if(mark[x] == 0 && pi[x] < min_dist){
				min_dist = pi[x];
				u = x;
			}
		}
		//2b.Danh dau u
		mark[u] = 1;
		
		//3c.Cap nhat lai pi va p cua cac dinh ke v cua u
		for(v = 1; v <= G->n; v++){
			if(G->A[u][v] != NO_EDGE){
				if(mark[v] == 0 && pi[v] > G->A[u][v]){
					pi[v] = G->A[u][v];
					p[v] = u;
				}
			}
		}
	}
	//3.Dung cay dua vao p[u]: them cac cung(p[u], u) vao cay T
	init_Graph(pT, G->n);
	int sum_w = 0;
	
	for(u = 1; u <= G->n; u++){
		if(p[u] != -1){
			int w = G->A[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum_w = sum_w + w;
		}
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m, u, v, w, e;
	//Doc du lieu tu tap tin dt.txt
	freopen("prim.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int sum_w = Prim(&G, &T, 1);
	printf("%d\n", sum_w);
	int i, j;
	for(i = 1; i <= T.n; i++){
		for(j = 1; j <= T.n; j++){
			if(T.A[i][j] != NO_EDGE){
				printf("%d %d %d\n", i, j, T.A[i][j]);
			}
		}
	}
	return 0;
}
