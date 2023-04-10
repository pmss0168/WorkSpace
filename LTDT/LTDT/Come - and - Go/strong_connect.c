#include<stdio.h>
#define MAX_N 20

/*-------------------------------Graph--------------------------------*/
typedef struct{
	int A[MAX_N][MAX_N];
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

void add_edges(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

int adjacent(Graph *G, int u, int v){
	return G->A[u][v] != 0;
}

/*-------------------------------List--------------------------------*/
typedef struct{
	int data[MAX_N];
	int size;
}List;

void MakenullList(List *L){
	L->size = 0;
}

int element_at(List L, int i){
	return L.data[i-1];
}

void appendList(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

List neigbors(Graph G, int u){
	List L;
	MakenullList(&L);
	int v;
	for(v = 1; v <= G.n; v++){
		if(G.A[u][v] != 0){
			appendList(&L, v);
		}
	}
	return L;
}

/*-------------------------------List--------------------------------*/
typedef struct{
	int stack[MAX_N];
	int Top_idx;
}Stack;

void MakenullStack(Stack *S){
	S->Top_idx = MAX_N;
}

int Top(Stack S){
	return S.stack[S.Top_idx];
}

int Push(Stack *S, int x){
	S->Top_idx = S->Top_idx - 1;
	S->stack[S->Top_idx] = x;
}

int Pop(Stack *S){
	S->Top_idx = S->Top_idx + 1;
}

/*-------------------------------strong_connected--------------------------------*/

int num[MAX_N];
int min_num[MAX_N];
int k;
int on_stack[MAX_N];

int min(int x, int y){
	return x < y ? x : y;
}
void strong_connect(Graph *G, int x){
	Stack S; MakenullStack(&S);
	num[x] = min_num[x] = k; k++;
	Push(&S, x);
	on_stack[x] = 1;	
	List list_ = neigbors(*G, x);
	int j;
	/* xet cac dinh ke cua no */
	for(j = 1; j <= list_.size; j++){
		int y = element_at(list_, j);
		if(num[y] < 0){
			strong_connect(G, y);
			min_num[y] = min(min_num[x], min_num[y]);
		} else if(on_stack[y] == 1){
			min_num[x] = min(min_num[x], num[y]);
		}
	}
	if(num[x] == min_num[x]){
		int w;
		do{
			w = Top(S);
			Pop(&S);
			on_stack[w] = 0;
		} while(w != x);
	}
}

int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 0; e < m; e++){
		scanf("%d%d", &u, &v);
		add_edges(&G, u, v);
	}
	int i;
	for(i = 1; i <= n; i++){
		num[i] = -1;
	}
	k = 1;
	int j, count = 0;
	for(j = 1; j <= n; j++){
		if(num[j] < 0){
			count++;
			strong_connect(&G, j);
		}
	}
	if(count == 1) printf("%d", count);
	else printf("%d", count);
	return 0;
}
