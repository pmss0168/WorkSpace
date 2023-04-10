#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100
#define MAX_VERTICES 100

typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
	int size;
} List;

typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;
typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} Stack;

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
	return S->size == 0;
}
/* Tao danh sach rong */
void make_null(List* L) {
	L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1
*/
ElementType element_at(List* L, int i) {
	return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
	return L->size;
}
/*****************************************/



void init_graph(Graph* G, int n) {
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y) {
	G->A[x][y] += 1;
	G->A[y][x] += 1; 
}

int adjacent(Graph* G, int x, int y) {
	return G->A[x][y] != 0;
}

int degree(Graph* G, int x) {
	int y, deg = 0;
	for (y = 1; y <= G->n; y++)
			deg += G->A[x][y];
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

void DFS(Graph* G, int b, int mark[]){
	Stack L;

	make_null_stack(&L);
	
	int j;
	push(&L,b);
	mark[b] = 1;
	
	while(!empty(&L)){
		int x = top(&L); 
		pop(&L);

		printf("%d\n", x);
		
		List list = neighbors(G, x);
		
		for ( j = 1; j <= list.size; j++){
			int y = element_at(&list, j);
			if (mark[y] == 0) {
				mark[y] = 1;
				push(&L, y);
			}
		}
	}
	for ( j = 1; j <= G->n; j++){
		if (mark[j] == 0){
			DFS(G,j,mark);
		}
	}
}

int main(){
	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int mark[MAX_VERTICES];
	int j;
	for (j = 1; j <= G.n; j++)
		mark[j] = 0;
	DFS(&G,1,mark);
	return 0;
}
