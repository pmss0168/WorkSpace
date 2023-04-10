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

#define NO_COLOR -1
#define BLUE 1
#define RED 2
int color[MAX_VERTICES];
int conflict = 0;

void colorize(Graph* G, int u, int c){
	color[u] = c;
	int j, S = RED + BLUE;
	List list = neighbors(G, u);
	for(j = 1; j <= list.size; j++){
		int y = element_at(&list, j);
		if(color[y] == NO_COLOR)
			colorize(G,y,S - c);
		else
			if(color[y] == color[u])
				conflict = 1;
	}
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
	int j;
	for(j = 1; j <= G.n; j++){
		color[j] = NO_COLOR;
	}
	colorize(&G,1,BLUE);
	if(conflict == 1)
		printf("IMPOSSIBLE");
	else{
		for(u = 1; u <= G.n; u++){
			if(color[u] == BLUE)
				printf("%d ",u);
		}
		printf("\n");
		for(u = 1; u <= G.n; u++){
			if(color[u] == RED)
				printf("%d ",u);
		}
	}
	return 0;
}