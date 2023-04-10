#include<stdio.h>
#define MAX_N 100
#define NO_EDGE 0
#define oo 999999
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
			G->A[i][j] = NO_EDGE;
		}
	}
}

//them cung va trong so
void add_edges(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

/*-----------------List-----------------*/
//khai bao cau truc List
typedef struct{
	int data[MAX_N];
	int size;
}List;

//khoi tao danh sach
void make_null_List(List *L){
	L->size = 0;
}

//them phan tu x vao cuoi danh sach
void push_back(List *L, int x){
	L->data[L->size] = x;
	L->size = L->size + 1;
}

//tra ve phan tu thu i trong danh sach
int element_at(List *L, int i){
	return L->data[i - 1];
}

//Coppy List1 qua List2
void copy_list(List *L1, List *L2){
	make_null_List(L1);
	int i;
	for(i = 1; i <= L2->size; i++){
		int u = element_at(L2, i);
		push_back(L1, u);
	}
}

int r[MAX_N];

void rank(Graph *G){
	int d[MAX_N]; //Luu bac cac dinh
	//Tinh bac vao cua cac dinh d[u]
	int u, x;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
		for(x = 1; x <= G->n; x++){
			if(G->A[x][u] != 0){
				d[u] = d[u] + 1;
			}
		}
	}
	//Su dung 2 danh sach S1, S2
	List S1, S2;
	//Tim goc, dua vao S1
	make_null_List(&S1);
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			push_back(&S1, u);
		}
	}
	//Vong lap chinh, lap den khi S1 rong thi dung
	int k = 0;
	while(S1.size > 0){
		make_null_List(&S2);
		int i;
		for(i = 1; i <= S1.size; i++){
			u = element_at(&S1, i);
			r[u] = k;
			
			//Xoa dinh u <=> giam bac vao cua cac dinh ke v cua u
			int v;
			for(v = 1; v <= G->n; v++){
				if(G->A[u][v] != 0){
					d[v] = d[v] - 1;
					if(d[v] == 0){
						push_back(&S2, v);
					}
				}
			}
		}
		copy_list(&S1, &S2); //copy S1 vao S2
	    k = k + 1; //Tang hang ke tiep cho cac goc moi
	}
}

int main(){	
	Graph G;
	int n, m, u, v, e;
	freopen("dt.txt", "r", stdin); 
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edges(&G, u, v);
	}
	rank(&G);
	for(e = 1; e <= n; e++){
		printf("%d\n", r[e]);
	}
	return 0;
}
