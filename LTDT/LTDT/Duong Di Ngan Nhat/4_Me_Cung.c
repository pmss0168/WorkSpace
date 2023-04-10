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

//thuat toan Moore-Dijkstra
int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];

void MooreDijkstra(Graph *G, int s){
	int u, v, it;
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
		mark[u] = 0;
	}
	
	pi[s] = 0; //Chieu dai duong di ngan nhat tu s den chinh no bang 0
	p[s] = -1;//truoc dinh s khong co dinh nao ca
	
	//lap n-1 lan
	for(it = 1; it < G->n; it++){
		
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
	int M, N;
	freopen("mecung.txt","r",stdin);
	scanf("%d%d", &M, &N);
	int i, j, MaTran[MAX_N][MAX_N], var, n = 0, mark_n[MAX_N], z;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			scanf("%d", &var);
			MaTran[i][j] = var;
			z = (i * N + j) + 1;
			if(mark_n[z] == 1){
				continue;
			}
			else{
				mark_n[z] = 1;
				n = n + 1;
			}
		}
	}
	init_Graph(&G, n);
	
	//4 o xung quanh cua 1 o: tren, duoi, trai, phai
	int di[] = {-1, 1, 0, 0};
	int dj[] = {0, 0, -1, 1};
	
	//Duyet toan bo ma tran de them cung
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			int u = (i*N + j) + 1;
			
			//Doi dinh u thanh o (i, j)
			int i = (u - 1)/N;
			int j = (u - 1)%N;
			
			//Duyet qua 4 o ke voi o (i, j)
			int k;
			for(k = 0; k < 4; k++){
				int ii = i + di[k];
				int jj = j + dj[k];
				//Kiem tra o (ii, jj) co nam trong me cung hay khong
			    if(ii >= 0 && ii < M && jj >= 0 && jj < N){
				    int v = ii*N + jj;
			 	    add_edges(&G, u, v, MaTran[i][j]);
			    }
			}
		}
	}
	MooreDijkstra(&G, 1);
	printf("%d", pi[((M-1)*N + (N-1)) + 1]);
	return 0;
}











