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

/*--------------------------------Queue--------------------------------*/

typedef struct{
	int A[MAX_N];
	int Front, Rear;
}Queue;

void MakenullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

int EmptyQueue(Queue *Q){
	return Q->Front == -1;
}

void EnQueue(Queue *Q, int x){
	if(EmptyQueue(Q)){
		Q->Front = 0;
	}
	Q->Rear = Q->Rear + 1;
	Q->A[Q->Rear] = x;
}

void DeQueue(Queue *Q){
	Q->Front = Q->Front + 1;
	if(Q->Front > Q->Rear){
		MakenullQueue(Q);
	}
}

int Front(Queue *Q){
	return Q->A[Q->Front];
}

/*--------------------------------Topo_Sort--------------------------------*/

void Topo_Sort(Graph *G, List *L){
	int d[MAX_N];
	
	//Tinh bac vao cua u
	int u, x;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
		for(x = 1; x <= G->n; x++){
			if(G->A[x][u] != 0){
				d[u] = d[u] + 1;
			}
		}
	}
	
	Queue Q;
	//Lam rong hang doi Q
	MakenullQueue(&Q);
	
	//Dua cac dinh co d[u] = 0 vao hang doi
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			EnQueue(&Q, u);
		}
	}
	
	//Lam rong danh sach L
	MakenullList(L);
	
	//Vong lap chinh, lap den khi Q rong thi dung
	while(!EmptyQueue(&Q)){
		u = Front(&Q);
		DeQueue(&Q);
		AppendList(L, u);
		//Xoa dinh u <=> giam bac vao cua cac dinh ke v cua u
		int v;
		for(v = 1; v <= G->n; v++){
			if(G->A[u][v] != 0){
				d[v] = d[v] - 1;
				if(d[v] == 0){
					EnQueue(&Q, v);
				}
			}
		}
	}
}


int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("Topo1.txt", "r", stdin); 
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	List L;
	Topo_Sort(&G, &L);
	int i;
	for(i = 1; i <= L.n; i++){
		printf("%d ", Element_at(&L, i));
	}
	return 0;
}
