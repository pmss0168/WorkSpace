#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef struct{
	int data[MAX_ELEMENTS];
	int size;
}Stack;
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
void make_null_stack(Stack* S){
	S->size = 0;
}
void push(Stack* S, int x){
	S->data[S->size] = x;
	S->size++;
}
int top(Stack* S){
	return S->data[S->size - 1];
}
void pop(Stack* S){
	S->size--;
}
int empty(Stack* S){
	return S->size==0;
}
void make_null(List* L) {
	L->size = 0;
}
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
ElementType element_at(List* L, int i) {
	return L->data[i-1];
}
int count_list(List* L) {
	return L->size;
}
typedef struct {
	int n; //n so dinh
	//ma tran dinh - dinh
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;
void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->A[i][j] = 0;
}
void add_edge(Graph *G, int x, int y){
	G->A[x][y] += 1; 
	G->A[y][x] += 1; 
}
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}
int degree(Graph* G, int x){
	int y, deg = 0;
	for(y = 1; y <= G->n; y++){
		deg += G->A[x][y];
	}
	return deg;
}
List neighbors(Graph* G, int x) {
	int y;
	List list;
	make_null(&list);
	for (y = 1; y <= G->n; y++)
		if (adjacent(G, x, y))
	push_back(&list, y);
	return list;
}
int mark[MAX_VERTICES];
void DFS(Graph* G, int b){
	int j;
	Stack L;
	make_null_stack(&L);
	//Khoi tao mark, chua dinh nao duoc duyet
	push(&L,b);
	mark[b] = 1;
	while(!empty(&L)){
		int x = top(&L);
		pop(&L);
		printf("%d\n",x);
		List list = neighbors(G, x);
		for(j = 1; j <= list.size; j++){
			int y = element_at(&list, j);
			if(mark[y] != 1){
				mark[y] = 1;
				push(&L,y);
			}
		}
	}
	for(j = 1; j <= G->n; j++)
	    if(mark[j] == 0)
	        DFS(G,j);
}

int main(){
	Graph G;
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? d?ng này.
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	DFS(&G,1);
	return 0;
}