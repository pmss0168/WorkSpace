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
	G->W[v][u] = w;
}

//thuat toan Moore-Dijkstra
int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];
int tong;

void MooreDijkstra(Graph *G, int s, int t){
	int u, v, it;
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
		mark[u] = 0;
	}
	
	pi[s] = 0; //Chieu dai duong di ngan nhat tu s den chinh no bang 0
	p[s] = -1;//truoc dinh s khong co dinh nao ca
	
	tong = 0;
	//lap n-1 lan
	for(it = 1; it <= G->n; it++){
		
		//1.Tim u co mark[u] == 0 va co pi[u] nho nhat
		int j, min_pi = oo;
		for(j = 1; j <= G->n; j++){
			if(mark[j] == 0 && pi[j] < min_pi){
				min_pi = pi[j];
				u = j;
			}
		}
		//2.Danh dau u da xet
		mark[u] = 1;
		if(u == t){
			tong = pi[u];
		}
		
		//3.Cap nhat pi va p cua cac dinh ke cua v (neu thoa)
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
	freopen("dothi.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v, w;
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edges(&G, u, v, w);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	MooreDijkstra(&G, s, t);
	printf("%d", tong);
	return 0;
}
