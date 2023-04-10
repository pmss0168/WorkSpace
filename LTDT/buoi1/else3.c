#include<stdlib.h>
#include<stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MAX_ELEMENTS 100

//STACK
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
//LIST
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
	int n;
	int m;
	int A [MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *G, int n){
	int i, j;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->A[i][j] = 0;
}
void add_edge(Graph *G,int e, int x, int y){
	G->A[x][e] = 1; 
	G->A[y][e] = 1; 
}
int adjacent(Graph* G, int x, int y) {
	int e;
	for (e = 1; e <= G->m; e++)
		if (G->A[x][e] == 1 && G->A[y][e] == 1)
			return 1;
	return 0;
}

int degree(Graph* G, int x){
	int y, deg = 0;
	for(y = 1; y <= G->m; y++){
		if(G->A[x][y] == 1)
			deg++;
	}
	return deg;
}
//List neighbors(Graph* G, int x) {
//	int y;
//	List list;
//	make_null(&list);
//	for (y = 1; y <= G->n; y++)
//		if (adjacent(G, x, y))
//	push_back(&list, y);
//	return list;
//}
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


//DFS
int mark[MAX_VERTICES];
void DFS(Graph* G){
	int j;
	Stack L;
	make_null_stack(&L);
	//Khoi tao mark, chua dinh nao duoc duyet
	for (j = 1; j <= G->n; j++) {
		mark[j] = 0;
	}
	push(&L,1);
	while(!empty(&L)){
		int x = top(&L);
		pop(&L);
		if(mark[x] != 0)
			continue;
		mark[x] = 1;
		List list = neighbors(G, x);
		for(j = 1; j <= list.size; j++){
			int y = element_at(&list, j);
			push(&L,y);
		}
	}
}
int connect(Graph* G){
	int j;
	DFS(G);
	for(j = 1; j <= G->n; j++){
		if(!mark[j]){
			return 0;
			break;
		}
	}	
	return 1;
}

int main(){
	Graph G;
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? d?ng này.
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G ,e , u, v);
	}
	if(connect(&G) == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}