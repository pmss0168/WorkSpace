#include<stdio.h>
#define MAX_N 100

/*--------------------------------Graph--------------------------------*/

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

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

/*--------------------------------List--------------------------------*/

typedef struct{
	int A[MAX_N];
	int n;
}List;

int EmptyList(List *L){
	return L->n == 0;
}
void MakenullList(List *L){
	L->n = 0;
}

void AppendList(List *L, int x){
	L->A[L->n] = x;
	L->n++;
}

int Element_at(List *L, int i){
	return L->A[i-1];
}

void Coppy(List *L1, List *L2){
	MakenullList(L1);
	int i;
	for(i = 1; i <= L2->n; i++){
		int u = Element_at(L2, i);
		AppendList(L1, u);
	}
}
/*--------------------------------Rank--------------------------------*/

int r[MAX_N];
void Rank(Graph *G){
	int d[MAX_N];
	
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
	
	//Su dung 2 danh sach S1 va S2
	List S1, S2;
	MakenullList(&S1);
	//Tim goc, dua vao S1
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			AppendList(&S1, u);
		}
	}
	int k = 0;
	//Vong lap chinh lap den khi S1 rong thi dung
	while(!EmptyList(&S1)){
		MakenullList(&S2);
		int i;
		for(i = 1; i <= S1.n; i++){
			u = Element_at(&S1, i);
			r[u] = k;
			
			//xoa dinh u <=> giam bac vao cua cac dinh ke v cua u
			int v;
			for(v = 1; v <= G->n; v++){
				if(G->A[u][v] != 0){
					d[v] = d[v] - 1;
					if(d[v] == 0){
						AppendList(&S2, v);
					}
				}
			}
		}
		Coppy(&S1, &S2);
		k = k + 1;
	}
}


int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("rank.txt", "r", stdin); 
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	Rank(&G);
	int i;
	for(i = 1; i <= n; i++){
		printf("r[%d] = %d\n", i, r[i]);
	}
	return 0;
}
