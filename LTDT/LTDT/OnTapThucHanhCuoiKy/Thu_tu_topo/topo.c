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
	G->W[u][v] = 1;
	G->W[v][u] = 1;
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


/*-----------------Queue-----------------*/

//Khai bao cau truc hang doi

typedef struct{
	int A[MAX_N];
	int Front, Rear;
}Queue;

void MakenullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

int EmptyQueue(Queue Q){
	return Q.Front == -1;
}

int FullQueue(Queue Q){
	return Q.Rear - Q.Front + 1 == MAX_N;
}
int Front(Queue Q){
	return Q.A[Q.Front];
}

void EnQueue(Queue *Q, int x){
	if(!FullQueue(Q)){
		if(EmptyQueue){
			Q->Front = 0;
		}
		Q->Rear = Q->Rear + 1;
		Q->A[Q->Rear] = x;
	}
}

void DeQueue(Queue *Q){
	if(!EmptyQueue(*Q)){
		Q->Front = Q->Front + 1;
		if(Q->Front > Q->Rear){
			MakenullQueue(Q);
		}
	}
}

/*-----------------/Queue-----------------*/



/*-----------------topo_sort-----------------*/

void topo_sort(Graph *G, List *L){
	
	//1.Tinh bac vao cua dinh u
	int u, x;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
		for(x = 1; x <= G->n; x++){
			if(G->A[x][u] != 0){
				d[u]++;
			}
		}
	}
	Queue Q; MakenullQueue(&Q);
	
	//2.Dua cac dinh co bac vao bang 0 vao hang doi
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			EnQueue(&Q, u);
		}
	}
	
	//3.Lap den khi Q rong
	while(!EmptyQueue(Q)){
		u = Front(Q);
		DeQueue(&Q);
		appendList(L, u);
		
		//4.Xoa dinh u <=> giam bac vao cua cac dinh ke v cua u
		for(v = 1; v <= G->n; v++){
			if(G->A[u][v] != 0){
				d[v]--;
				if(d[v] == 0){
					EnQueue(&Q, v);
				}
			}
		}
	}
}

/*-----------------/topo_sort-----------------*/

int main(){
	
	return 0;
}



































