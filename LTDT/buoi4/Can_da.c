#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100
#define MAX_VERTICES 500

typedef int Element_Type;
typedef struct{
	int size;
	Element_Type data[MAX_ELEMENTS];
}List;
void make_null_list(List* L){
	L->size = 0;
}
void push_back(List* L, int x){
	L->data[L->size] = x;
	L->size++;
}
Element_Type element_at(List* L, Element_Type i){
	return L->data[i-1];
}
int size(List* L){
	return L->size;
}
void copy_list(List* L1, List* L2){
	make_null_list(L1);
	int i;
	for(i = 1 ; i <= L2->size; i++)
		push_back(L1,element_at(L2,i));
}
typedef struct{
	int front, rear;
	Element_Type data[MAX_ELEMENTS];
}Queue;
void make_null_queue(Queue* Q){
	Q->front = -1;
	Q->rear = -1;
}
void enqueue(Queue* Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}
void dequeue(Queue* Q){
	Q->front++;
}
Element_Type front(Queue* Q){
	return Q->data[Q->front];
}
int empty(Queue* Q){
	return Q->front > Q->rear;
}
typedef struct{
	int  n;
	Element_Type data[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph* G,int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->data[i][j] = 0;
}
void add_edge(Graph* G, int u, int v){
	G->data[u][v] = 1;
}
void add_edge1(Graph* G, int u, int v, int w){
	G->data[u][v] = w;
}
int degree(Graph* G, int u){
	int i, deg = 0;
	for(i = 1; i <= G->n; i++)
		deg += G->data[u][i];
	return deg;
}
int adjacent(Graph* G, int u, int v){
	return G->data[u][v] != 0;
}

int rank[MAX_VERTICES];
void Topo(Graph* G){
	int d[MAX_VERTICES];
	int x, u;
	for(u = 1; u <= G->n; u++)
		d[u] = 0;
	for(x = 1; x <= G->n; x++)
		for(u = 1; u <= G->n; u++)
			if(G->data[x][u] != 0)
				d[u]++;
	List S1,S2;
	make_null_list(&S1);
	for(u = 1; u <= G->n; u++)
		if(d[u] == 0)
			push_back(&S1, u);
	int k = 1, i;
	while(S1.size > 0){
		make_null_list(&S2);
		for(i = 1; i <= S1.size; i++){
			int u = element_at(&S1, i);
			rank[u] = k;
			int v;
			for(v = 1; v <= G->n; v++)
				if(G->data[u][v] != 0){
					d[v]--;
					if(d[v] == 0)
						push_back(&S2, v);
				}
		}
		copy_list(&S1, &S2);
		k++;
	}
}

int main(){
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	Topo(&G);
	int i,j;
	List bang[MAX_VERTICES];
	for(i = 1; i <= G.n; i++)
		make_null_list(&bang[i]);
	for(i = 1; i <= G.n; i++)
		push_back(&bang[rank[i]],i);
	for(i = 1; i <= G.n; i++)
		for(j = 1; j <= bang[i].size; j++)
			printf("%d ", element_at(&bang[i],j));
}
