#include<stdlib.h>
#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;


typedef struct {
int n; /* n: so dinh */
/* mang danh sach cac dinh ke */
List adj[MAX_VERTICES];
} Graph;

/* Tao danh sach rong */
void make_null(List* L) {
	L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1*/
ElementType element_at(List* L, int i) {
	return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
	return L->size;
}

/* Khoi tao do thi G co n dinh */
void init_graph(Graph* G, int n) {
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++)
		make_null(&G->adj[i]);
}
/* Them cung e = (x, y) vao do thi G */
void add_edge(Graph* G, int x, int y) {
	push_back(&G->adj[x], y); //y ke v?i x
	push_back(&G->adj[y], x); //x ke voi y
}	
/* Kiem tra y co ke voi x khong */
int adjacent(Graph* G, int x, int y) {
	int j;
	for (j = 1; j <= G->adj[x].size; j++)
	if (element_at(&G->adj[x], j) == y)
		return 1;
	return 0;
}
/* Tinh bac cua dinh x: deg(x) */
int degree(Graph* G, int x) {
	return G->adj[x].size;
}

//Ham main
int main(){
	Graph G;
	int n, u, v, m, e;
	FILE* file = fopen("dothi2.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G,n);
	for(e = 1; e <= m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G,u,v);
	}
	for(v = 1; v <= n; v++)
		printf("deg(%d) = %d\n",v,degree(&G,v));
	return 0;
}
