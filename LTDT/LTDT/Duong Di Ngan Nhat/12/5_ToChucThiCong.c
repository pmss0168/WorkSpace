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

int max(int x, int y){
	return x > y ? x : y;
}

int min(int x, int y){
	return x < y ? x : y;
}
//Luu thoi gian hoan thanh cong viec
int d[MAX_N];

//Doc danh sach cac cong viec va tao do thi
int main(){
	Graph G;
	int n, u, x, v, j;
	
	//1.Doc do thi
	freopen("DuAn.txt","r",stdin);
	scanf("%d", &n);
	
	//1a.Tao do thi co n+2 dinh (alpha = n+1 va beta = n+2)
	init_Graph(&G, n);
	int alpha = n+1, beta = n+2;
	d[alpha] = 0; //Thoi gian hoan thanh cua alpha bang 0
	
	//1b.Doc danh sach cac cong viec
	for(u = 1; u <= n; u++){
		scanf("%d", &d[u]); //Thoi gian hoan thanh cong viec u
		do{
			scanf("%d", &x); //Doc cong viec truoc u
			if(x > 0){
				add_edges(&G, x, u);
			}
		}while(x > 0); //Doc den khi gap so 0 thi dung
	}
	
	//2.Them cung noi alpha voi cac dinh co bac vao = 0
	for(u = 1; u <= n; u++){
		int deg_neg = 0;
		for(x = 1; x <= n; x++){
			if(G.A[x][u] != 0){
				deg_neg = deg_neg + 1; //deg_neg la bac vao cua dinh u
			}
			if(deg_neg == 0){
				add_edges(&G, alpha, u);
			}
		}
	}
	
	//3.Them cung noi cac dinh co bac ra = 0 vao beta
	for(u = 1; u <= n; u++){
		int deg_pos = 0;
		for(v = 1; v <= n; v++){
			if(G.A[u][v] != 0){
				deg_pos = deg_pos + 1; //deg_pos la bac ra cua dinh u
			}
			if(deg_pos == 0){
				add_edges(&G, u, beta);
			}
		}
	}
	
	//4.Xep thu tu cac dinh theo giai thuat sap xep topo
	List L;
	topo_sort(&G, &L);
	
	//5.Tinh t[u] : Thoi diem som nhat
	int t[MAX_N];
	t[alpha] = 0;
	
	//alpha chac chan nam dau danh sach, cac dinh con lai di tu 2 den L.size
	for(j = 2; j <= L.size; j++){
		u = element_at(&L, j);
		t[u] = -oo; //Vo cung be : -999999
		for(x = 1; x <= G.n; x++){
			if(G.A[x][u] > 0){
				t[u] = max(t[u], t[x] + d[x]);
			}
		}
	}
	
	//6.Tinh T[u] : Thoi diem tre nhat
	int T[MAX_N];
	T[beta] = t[beta];
	
	//beta chac chan nam cuoi danh sach, di nguoc lai tu L.size-1 ve 1
	for(j = L.size-1; j >= 1; j--){
	 u = element_at(&L, j);
		T[u] = +oo; //Vo cung lon: 999999
		for(v = 1; v <= G.n; v++){
			if(G.A[u][v] > 0){
				T[u] = min(T[u], T[v] - d[u]);
			}
		}
	}
	
	//7.In ket qua : in t[u] va T[u] ra man hinh
	int i;
	for(i = 1; i <= n; i++){
		printf("t[%d] = %d, T[%d] = %d\n", i,t[i],i,T[i]);
	}
	return 0;
}
