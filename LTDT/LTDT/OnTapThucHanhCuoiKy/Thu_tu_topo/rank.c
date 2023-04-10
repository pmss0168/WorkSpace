#include<stdio.h>
#include<stdio.h>
#define MAX_N 100
/*-----------------Graph-----------------*/

//khai bao cau truc Graph
typedef struct{
	int A[MAX_N][MAX_N];
	int n;
}Graph;

//khoi tao do thi n dinh, 0 cung
void init_Graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->A[i][j] = 0;
		}
	}
}

//them cung va trong so
void add_edges(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

/*-----------------/Graph-----------------*/


/*-----------------List-----------------*/

//Khai bao cau truc danh sach
typedef struct{
	int A[MAX_N];
	int n;
}List;

//Khoi tao danh sach
void MakenullList(List *L){
	L->n = 0;
}

//Them danh sach vao sau phan tu cuoi
void appendList(List *L, int x){
	L->A[L->n] = x;
	L->n++;
}

//Phan tu tai vi tri i
int element_at(List L, int i){
	return L.A[i-1];
}

//In danh sach
void print(List L, int n){
	int i;
	for(i = 1; i <= n; i++){
		int e = element_at(L, i);
		printf("%d ", e);
	}
}

//Ham chep danh sach
void coppy_list(List *L1, List *L2){
	MakenullList(L1);
	int i;
	for(i = 1; i <= L2->n; i++){
		int v = element_at(*L2, i);
		appendList(L1, v);
	}
}
/*-----------------/List-----------------*/


/*-----------------rank-----------------*/

int r[MAX_N];

//Ham xep hang
void rank(Graph *G){
	int d[MAX_N];
	
	//1.Tinh bac vao cua cac dinh
	int u, x;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
		for(x = 1; x <= G->n; x++){
			if(G->A[x][u] != 0){
				d[u]++;
			}
		}
	}
	
	//2.Su dung 2 danh sach S1, S2
	List S1, S2;
	
	//3.Dua cac dinh co bac vao = 0 vao S1
	MakenullList(&S1);
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			appendList(&S1, u);
		}
	}
	
	//4.Lap den khi S1 rong
	int k = 0, i;
	while(S1.n > 0){
		MakenullList(&S2);
		for(i = 1; i <= S1.n; i++){
			u = element_at(S1, i);
			r[u] = k;
			
			//5.Xoa dinh u <=> giam bac vao cua cac dinh ke v
			int v;
			for(v = 1; v <= G->n; v++){
				if(G->A[u][v] != 0){
					d[v]--;
					if(d[v] == 0){
						appendList(&S2, v);
					}
				}
			}
		}
		coppy_list(&S1, &S2);
		k++;
	}
}

int main(){
	freopen("rank.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edges(&G, u, v);
	}
	rank(&G);
	int i;
	for(i = 1; i <= n; i++){
		printf("%d\n", r[i]);
	}
	return 0;
}









































