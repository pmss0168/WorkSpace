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

/*-----------------Queue-----------------*/
//khai bao cau truc hang doi
typedef int ElementType;
typedef struct{
	ElementType Elements[MAX_N];
	int Front, Rear;
}Queue;

//khoi tao hang doi
void MakenullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

//kiem tra rong
int Empty_Queue(Queue Q){
	return Q.Front == -1;
}

//kiem tra day
int Full_Queue(Queue Q){
	return Q.Rear - Q.Front+1 == MAX_N;
}

//them phan tu
void EnQueue(ElementType x, Queue *pQ){
	if(!Full_Queue(*pQ)){
		if(Empty_Queue(*pQ)){
			pQ->Front = 0;
		}
		pQ->Rear = pQ->Rear+1;
		pQ->Elements[pQ->Rear] = x;
	}
}

//ham lay phan tu
ElementType Front(Queue *Q){
	return Q->Elements[Q->Front];
}

//xoa phan tu
void DeQueue(Queue *pQ){
	if(!Empty_Queue(*pQ)){
		pQ->Front = pQ->Front+1;
		if(pQ->Front > pQ->Rear){
			MakenullQueue(pQ);
		}
	}
}

void topo_sort(Graph *G, List *L){
	int d[MAX_N];
	//Tinh bac vao cua dinh u
	int u, x;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
		for(x = 1; x <= G->n; x++){
			if(G->A[x][u] != 0){
				d[u] = d[u] + 1;
			}
		}
	}
	Queue Q; MakenullQueue(&Q);
	//Dua cac dinh co d[u] = 0 vao hang doi
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			EnQueue(u, &Q);
		}
	}
	//Lam rong danh sach L
	make_null_List(L);
	//Vong lap chinh, lap den khi Q rong thi dung
	while(!Empty_Queue(Q)){
		u = Front(&Q);
		DeQueue(&Q);
		push_back(L, u);
		//Xoa dinh u <=> giam bac vao cua cac dinh ke v cua u
		int v;
		for(v = 1; v <= G->n; v++){
			if(G->A[u][v] != 0){
				d[v]--;
				if(d[v] == 0){
					EnQueue(v, &Q);
				}
			}
		}
	}
}

int main(){
	Graph G;
	List L;
	int n, m, u, v, e;
	freopen("dt.txt", "r", stdin); 
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edges(&G, u, v);
	}
	topo_sort(&G, &L);
	int i; 
	for(i = 1; i <= L.size; i++){
		printf("%d ", element_at(&L, i));
	}
	return 0;
}
