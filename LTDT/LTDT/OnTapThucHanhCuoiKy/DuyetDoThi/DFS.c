#include<stdio.h>
#define Max_List 50
#define Max_Stack 50
#define Max_G 20

/*----------------------------------------------Cau Truc Do Thi----------------------------------------------*/

typedef struct{
	int A[Max_G][Max_G];
	int n;
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
	G->A[v][u] = 1;
}

/*----------------------------------------------/Cau Truc Do Thi----------------------------------------------*/




/*----------------------------------------------Cau Truc Danh Sach----------------------------------------------*/

typedef struct{
	int A[Max_List];
	int size;
}List;

void MakenullList(List *L){
	L->size = 0;
}

void appendList(List *L, int x){
	L->A[L->size] = x;
	L->size++;
}

int element_at(List *L, int i){
	return L->A[i-1];
}

List Neigbours(Graph *G, int u){
	List L;
	MakenullList(&L);
	int v;
	for(v = 1; v <= G->n; v++){
		if(G->A[u][v] != 0){
			appendList(&L, v);
		}
	}
	return L;
}

/*----------------------------------------------/Cau Truc Danh Sach----------------------------------------------*/



/*----------------------------------------------Cau Truc Ngan Xep----------------------------------------------*/

typedef struct{
	int A[Max_Stack];
	int idx_Top;
}Stack;

void MakenullStack(Stack *S){
	S->idx_Top = Max_Stack;
}

int Top(Stack *S){
	return S->A[S->idx_Top];
}

int emptyStack(Stack *S){
	return S->idx_Top == Max_Stack;
}

void Push(Stack *S, int x){
	S->idx_Top = S->idx_Top - 1;
	S->A[S->idx_Top] = x;
}

void Pop(Stack *S){
	S->idx_Top = S->idx_Top + 1;
}

/*----------------------------------------------Duyet Do Thi(Chieu Sau)----------------------------------------------*/

int mark[Max_G];

List DFS(Graph *G, int s){
	List L; MakenullList(&L);
	Stack S; MakenullStack(&S);
	Push(&S, s);
	int u;
	while(!emptyStack(&S)){
		u = Top(&S); Pop(&S);
		if(mark[u] == 1){
			continue;
		}
		mark[u] = 1;
		appendList(&L, u);
		List lst = Neigbours(G, u);
		int i, v;
		for(i = 1; i <= lst.size; i++){
			v = element_at(&lst, i);
			if(mark[v] == 0){
				Push(&S, v);
			}
		}
	}
	return L;
}

/*----------------------------------------------/Duyet Do Thi(Chieu Sau)----------------------------------------------*/


/*----------------------------------------------main----------------------------------------------*/

int main(){
	Graph G;
	int n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i;
	for(i = 1; i <= n; i++){
		mark[i] = 0;
	}
	
	List list = DFS(&G, 1);
	for(i = 1; i <= list.size; i++){
		int v = element_at(&list, i);
		printf("%d\n", v);
	}
	return 0;
}

/*----------------------------------------------/main----------------------------------------------*/
