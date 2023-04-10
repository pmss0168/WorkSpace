#include<stdio.h>
#define MAX_M 100
#define MAX_N 100

/*-------------------Danh Sach Cung-------------------*/
typedef struct{
	int u, v;
	int w;
}Edge;

typedef struct{
	int n, m;
	Edge edge[MAX_M];
}Graph;

void init_Graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

//Do thi vo huong
void add_edge(Graph *G, int u, int v, int w){
	G->edge[G->m].u = u;
	G->edge[G->m].v = v;
	G->edge[G->m].w = w;
	G->m++;
}


/*-------------------Thuat Toan Kruskal-------------------*/

int parent[MAX_N];
//Tim goc cua dinh u
int findRoot(int u){
	while(parent[u] != u){
		u = parent[u];
	}
	return u;
}

int Kruskal(Graph *G, Graph *pT){
	
	//1.Sap xep cac cung cua G theo thu tu trong so tang dan
	int i, j;
	for(i = 0; i < G->m; i++){
		for(j = i+1; j < G->m; j++){
			if(G->edge[j].w < G->edge[i].w){
				Edge temp;
				temp = G->edge[j];
				G->edge[j] = G->edge[i];
				G->edge[i] = temp;
			}
		}
	}
	
	//2.Khoi tao PT khong chua cung nao, khoi tao bo quan ly cac bo phan lien thong
	init_Graph(pT, G->n);
	int u, v, w;
	for(u = 1; u < G->n; u++){
		parent[u] = u; //Moi dinh u la 1 bo phan lien thong
	}
	int sum_w = 0; //Tong trong so cac cung cua cay
	
	//3.Duyet qua cac cung cua G (da sap xep)
	int e;
	for(e = 0; e < G->m; e++){
		u = G->edge[e].u;
		v = G->edge[e].v;
		w = G->edge[e].w;
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if(root_u != root_v){
			//Them cung (u, v, w) vao cay pT
			add_edge(pT, u, v, w);
			//Gop 2 BPLT root_u va root_v lai
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m, u, v, w, e;
	//Doc du lieu tu tap tin dt.txt
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int sum_w = Kruskal(&G, &T);
	printf("%d\n", sum_w);
	for(e = 0; e < T.m; e++){
		if(T.edge[e].u < T.edge[e].v)
		   printf("%d %d %d\n", T.edge[e].u, T.edge[e].v, T.edge[e].w);
		else printf("%d %d %d\n", T.edge[e].v, T.edge[e].u, T.edge[e].w);
	}
	return 0;
}
