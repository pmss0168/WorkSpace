#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENTS 500
#define MAX_VERTICES 100
#define MAX_EDGE 1000
#define NO_EDGE -1
#define INFINITY 99999

//LIST
typedef int Element_Type;
typedef struct{
	int size;
	Element_Type data[MAX_ELEMENTS];
}List;
void make_null_list(List *L){
	L->size =  0;
}
void push_back(List *L, Element_Type x){
	L->data[L->size] = x;
	L->size++;
}
Element_Type element_at(List *L, Element_Type x){
	return L->data[x-1];
}
int count_list(List *L){
	return L->size;
}
//STACK
typedef struct{
	int idx;
	Element_Type data[MAX_ELEMENTS];
}Stack;
void make_null_stack(Stack *S){
	S->idx = -1;
}
int empty(Stack *S){
	return S->idx == -1;
}
Element_Type top(Stack *S){
	return S->data[S->idx];
}
void pop(Stack *S){
	S->idx--;
}
void push(Stack *S, Element_Type x){
	S->data[S->idx] = x;
	S->idx++;
}
//GRAPH
typedef struct{
	int u, v;	//dinh dau v, dinh cuoi v
	int w;		//trong so w
}Edge;
typedef struct{
	int n,m;
	Edge edges[MAX_EDGE];
}Graph;
void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}
void add_edge(Graph *G, int u, int v, int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

int p[MAX_VERTICES];
int pi[MAX_VERTICES];
int check[MAX_VERTICES][MAX_VERTICES];

void BellmanFord(Graph *G, int s){
	int i, j , it ;
	for (i = 1; i<= G->n; i++){
		pi[i] = INFINITY;
	}
	pi[s] = 0;
	p[s] = -1;
	for(it = 1; it <= G->n; it++){
		for(j = 0; j < G->m; j++){
			int u = G->edges[j].u;
			int v = G->edges[j].v;
			int w = G->edges[j].w;
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
		for(j = 1; j <= G->n; j++){
			check[it][j] = pi[j];
		}
	}
}

//Main
int main()
{
    freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, w, e, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	for(i = 1; i < n ;i++){
		for(j = 1; j <= n; j++)
			check[i][j] = 0;
	}
	
    BellmanFord(&G, 1);
//    for (i = 1; i <= G.n; i++)
//		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
	//Kiem tra chu trinh am 
	int negative_cycle = 0;
	for(i = 1; i < n-1; i++){
		for(j = 1; j < n; j++){
			if(check[i][j] != check[i+1][j])
				negative_cycle = 1;
				break;
		}
	}
	if(negative_cycle)
		printf("negative cycle");
	else
		printf("ok");
	return 0;
}

