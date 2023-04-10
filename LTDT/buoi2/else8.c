#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef struct{
	int data[MAX_ELEMENTS];
	int size;
}Stack;
void make_null_stack(Stack* S){
	S->size = -1;
}
void push(Stack* S, int x){
	S->data[S->size] = x;
	S->size++;
}
int top(Stack *S){
	return S->data[S->size];
}
void pop(Stack* S){
	S->size--;
}
int empty(Stack* S){
	return S->size == -1;
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
void add_edge(Graph *G, int x, int y, int p){
	if(p != 1){
		G->A[x][y] = 1; 
		G->A[y][x] = 1; 
	}
	else
		G->A[x][y] = 1;
}
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
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
int min(int x, int y){
	return x < y ? x : y;
}

int on_stack[MAX_VERTICES], num[MAX_VERTICES], min_num[MAX_VERTICES];
int k;
Stack S;
Stack C;

void strong_connect(Graph *G, int x)
{
    num[x] = min_num[x] = k;
    k++;
    push(&S, x);
    on_stack[x] = 1;
    
    //Xet dinh ke
    List list = neighbors(G, x);
    int j;
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
        if (num[y] < 0)
        {
            strong_connect(G, y);
            min_num[x] = min(min_num[x], min_num[y]);
        }
        else if (on_stack[y])
            min_num[x] = min(min_num[x], num[y]);
    }
	//Kiem tra x co la dinh khop
    if (num[x] == min_num[x])
    {
        push(&C, x);
        int w;
        do
        {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
        } while (w != x);
    }
}
void Tarjan(Graph *G)
{
    int v;
    for (v = 1; v <= G->n; v++)
    {
        num[v] = -1;
        on_stack[v] = 0;
    }
    k = 1;
    make_null_stack(&S);
    make_null_stack(&C);
    for (v = 1; v <= G->n; v++)
    {
        if (num[v] == -1)
            strong_connect(G, v);
    }
}
int Check(Graph *G)
{
    Tarjan(G);
    return (C.size + 1) == 1;
}
//MAIN
int main(){
	Graph G;
	int n, m, i, u, v, p;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i = 1; i <= m; i++){
		scanf("%d%d%d", &u, &v, &p);
		add_edge(&G, u, v, p);
	}
	if (Check(&G)) 
		printf("OKIE");
	else 
		printf("NO");
	return 0;
}