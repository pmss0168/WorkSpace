#include<stdio.h>
#define MAX_N 100
#define oo 999999
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

int max(int x, int y){
	return x > y ? x : y;
}

int min(int x, int y){
	return x < y ? x : y;
}

/*--------------------------------Topo_Sort--------------------------------*/

int d[MAX_N];
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
	int n, u, x, v, j, cv, day;
	
	//1. Doc do thi
	freopen("DAPM.txt","r",stdin);
	scanf("%d", &n);
	
	//1a. Tao do thi co n+2 dinh (alpha = n+1 va beta = n+2)
	init_Graph(&G, n+2);
	int alpha = n+1, beta = n+2;
	d[alpha] = 0; //Thoi gian hoan thanh alpha la 0
	
	//1b. Doc danh sach cac cong viec
	for(u = 1; u <= n; u++){
		scanf("%d", &d[u]); //Thoi gian hoan thanh cong viec u
		do {
			scanf("%d", &x); //Doc cong viec truoc cong viec u
			if(x > 0){
				add_edge(&G, x, u);
			}
		}while(x > 0); //Doc cho den khi gap 0 thi dung
	}
	
	scanf("%d%d", &cv, &day);
	
	//2. Them cung noi alpha voi cac dinh co bac vao = 0
	for(u = 1; u <= n; u++){
		int deg_neg = 0;
		for(x = 1; x <= n; x++){
			if(G.A[x][u] > 0){
				deg_neg++;
			}
		}
		if(deg_neg == 0){
			add_edge(&G, alpha, u);
		}
	}
	
	//3. Them cung noi cac dinh co bac ra = 0 vao beta
	for(u = 1; u <= n; u++){
		int deg_pos = 0;
		for(v = 1; v <= n; v++){
			if(G.A[u][v] > 0){
				deg_pos++;
			}
		}
		if(deg_pos == 0){
			add_edge(&G, u, beta);
		}
	}
	
	//4. Xep thu thu cac dinh theo giai thuat sap xep Topo
	List L;
	Topo_Sort(&G, &L);
	
	//5.Tinh t[u]
	int t[MAX_N];
	t[alpha] = 0;
	
	//alpha chac chan nam dau danh sach, cac dinh con lai di tu 2 den L.n
	for(j = 2; j <= L.n; j++){
		u = Element_at(&L, j);
		t[u] = -oo;
		for(x = 1; x <= G.n; x++){
			if(G.A[x][u] > 0){
				t[u] = max(t[u], t[x] + d[x]);
			}
		}
	}
	
	//6. tinh T[u]
	int T[MAX_N];
	T[beta] = t[beta];
	
	//beta chac chan nam cuoi danh sach, di nguoc lai tu L.n - 1 ve 1
	for(j = L.n-1; j >= 1; j--){
		u = Element_at(&L, j);
		T[u] = +oo;
		for(v = 1; v <= G.n; v++){
			if(G.A[u][v] > 0){
				T[u] = min(T[u], T[v] - d[u]);
			}
		}
	}
	
	//7.In ket qua
	if((day >= t[cv] && day <= T[cv])) printf("YES");
	else printf("NO");
	return 0;
}
