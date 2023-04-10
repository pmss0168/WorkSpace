#include<stdio.h>
#define MAX_Vertices 20
#define MAX_Length 20
#define MAXLength 50

//**************************do thi*********************************//
//khai bao cau truc do thi
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;
}Graph;

//khoi tao do thi
void init_Graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->A[i][j] = 0;
		}
	}
}

//ham them cung vo huong
void add_edges_vh(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

//ham them cung co huong
void add_edges_ch(Graph *G, int x, int y){
	G->A[x][y] = 1;
}

//ham kiem tra ke
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

//**************************danh sach*********************************//

//khai bao cau truc danh sach
typedef struct{
	int data[MAXLength];
	int size;
}List;

//khoi tao danh sach
void MakenullList(List *L){
	L->size = 0;
}

//them phan tu vao sau danh sach
void appendList(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

//lay 1 phan tu trong danh sach
int element_at(List *L, int i){
	return L->data[i-1];
}

//Tim lang gieng cua 1 dinh
List neighbours(Graph *G, int u){
	List L;
	MakenullList(&L);
	int i;
	for(i = 1; i <= G->n; i++){
		if(G->A[i][u] != 0){
			appendList(&L, i);
		}
	}
	return L;
}

//in danh sach
void printList(List L){
	int i;
	for(i = 0; i < L.size; i++){
		printf("%d\n", L.data[i]);
	}
}

//**************************ngan xep*********************************//

//khai bao cau truc ngan xep

typedef struct{
	int Elements[MAXLength];
	int Top_idx;
}Stack;

//khoi tao ngan xep
void MakenullStack(Stack *S){
	S->Top_idx = MAXLength;
}

//kiem tra rong
int EmptyStack(Stack S){
	return S.Top_idx == MAXLength;
}

//Lay 1 phan tu
int Top(Stack S){
	return S.Elements[S.Top_idx];
}

//Them phan tu
void Push(int x, Stack *S){
	S->Top_idx = S->Top_idx - 1;
	S->Elements[S->Top_idx] = x;
}

//Xoa phan tu
void Pop(Stack *S){
	S->Top_idx = S->Top_idx + 1;
}


//**************************DFS*********************************//

int MARK[MAXLength];
void DFS_Recursion(Graph *G, int x){
	if(MARK[x] == 1){
		return;
	}
	printf("%d\n", x);
	MARK[x] = 1;
	List list = neighbours(G, x);
	int i;
	for(i = 1; i <= list.size; i++){
		int v = element_at(&list, i);
		DFS_Recursion(G, v);
	}
}

int main(){
	freopen("Dothi.txt","r",stdin);
	Graph G;
	int m, n;
	scanf("%d%d",&n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 0; e < m; e++){
		scanf("%d%d", &u, &v);
		add_edges_vh(&G, u, v);
	}
	int i;
	for(i = 1; i <= G.n; i++){
		if(MARK[i] == 0){
			DFS_Recursion(&G, i);
		}
	}
	return 0;
}
