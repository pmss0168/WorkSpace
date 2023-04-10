#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
	int data[MAX_ELEMENTS];
	int size;
}Stack;
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
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
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
//GRAPH
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

int color[MAX_VERTICES];
int is_cycle = 0;
void DFS(Graph* G, int u, int p) {
	color[u] = GRAY;
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G,u,v)){
			if(v == p)			//v la cha cua p bo qua
				continue;
			if(color[v] == WHITE) //v chua duyet thi duyet
				DFS(G,v,u);
			if(color[v] == GRAY)  //v dang duyet tao thanh chu trinh
				is_cycle = 1;				
		}
	}
	color[u] = BLACK;
}

//MAIN
int main() {
// Kiem tra ton tai chu trinh doi voi do thi vo huong
	Graph G;
	int e, u, v, n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(v = 1; v <= G.n; v ++){
		color[v] = WHITE;
	}
	DFS(&G, 1, -1);
	if (is_cycle == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}