#include <stdio.h>
#define INFINITY 9999
#define MAX_VERTICES 500
#define NO_EDGE 0
typedef struct {
	int n; // Dinh
	int m;
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;
void init_graph(Graph* G, int n, int m) {
	G->n = n;
	G->m = m;
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
		G->A[i][j] = NO_EDGE;
		}
	}
}
#include <stdio.h>
#define MAX_ELEMENTS 100
// STACK
typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} Stack;
void make_null_stack(Stack* S) {
	S->size = 0;
}
void push(Stack* S, int x) {
	S->data[S->size] = x;
	S->size++;
}
int top(Stack* S) {
	return S->data[S->size - 1];
}
void pop(Stack* S) {
	S->size--;
}
int empty(Stack* S) {
	return S->size == 0;
}
// LIST
#define MAX_ELEMENTS 100
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
int adjeacent(Graph* G, int x, int y) {
	int e;
	for (e = 1; e <= G->m; e++)
	if (G->A[x][e] == 1 && G->A[y][e] == 1)
		return 1;
	return 0;
}
int degree(Graph* G, int x) {
	int e, deg = 0;
	for (e = 1; e <= G->m; e++)
		if (G->A[x][e] == 1)
			deg++;
	return deg;
}
void print_list(List L) {
	int i;
	for (i = 1; i <= L.size; i++) {
		printf("%d ", element_at(&L, i));
	}
}
List  neighbors(Graph* G, int x) {
	List ansList;
	make_null(&ansList);
	int col, row, temp;
	for(col = 1; col <= G->m; col++) {
		if(G->A[x][col] == 1) {
			for(row = 1; row <= G->n; row++) {
				if(G->A[row][col] == 1 && row != x) {
 					push_back(&ansList, row);
				}
			}
		}
	}
	int i, j;
	for(i = 1; i <= count_list(&ansList); i++) {
		for(j = i+1; j <= count_list(&ansList)-1; j++) {
			if(element_at(&ansList, i) > element_at(&ansList, j)) {
 				temp = ansList.data[i-1];
 				ansList.data[i-1] = ansList.data[j-1];
 				ansList.data[j-1] = temp;
 			}
			
			}
	}
	List checkList;
	make_null(&checkList);
	int check = 1;
	for(i = 1; i <= count_list(&ansList); i++) {
 		for(j = 1; j <= count_list(&checkList); j++) {
			if(element_at(&ansList, i) == element_at(&checkList, j)) {
 				check = 0;
			}
		}
		if(check) {
			push_back(&checkList, element_at(&ansList, i));
		}
	}

 	return checkList;
}
void add_edge(Graph* G, int e, int x, int y) {
	G->A[x][e] = 1;
	G->A[y][e] = 1;
}
#define MAX_VERTICES 500
int mark[MAX_VERTICES];
// Duyet do thi theo chieu sau
void dfs(Graph* G) {
	Stack L;
	make_null_stack(&L);
	// Khoi tao mark, chua dinh nao duoc duyet
	int j;
	for (j = 1; j <= G->n; j++) {
		mark[j] = 0;
	}
	// Dua 1 vao L, bat dau duyet tu dinh 1
	push(&L, 1);
	while (!empty(&L)) {
		int x = top(&L);
		pop(&L);
		if (mark[x] != 0)
			continue;
		mark[x] = 1;
		List list = neighbors(G, x);
		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
			push(&L, y);
		}
	}
}
int interconnected(Graph* G) {
	int i;
	dfs(G);
	for (i = 1; i <= G->n; i++) {
		if (!mark[i]) {
			return 0;
			break;
		}
	}
	return 1;
}


int main() {
// Kiem tra ton tai chu trinh doi voi do thi vo huong
	Graph G;
	int e, u, v, n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	if (interconnected(&G))
		printf("YES");
	else
		printf("NO");
	return 0;
}