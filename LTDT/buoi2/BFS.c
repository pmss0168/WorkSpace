#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

#define MAX_VERTICES 100
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

//Duyet do thi theo chieu rong
int mark[MAX_VERTICES];
void BFS(Graph* G, int b){
	Queue L;
	make_null_queue(&L);
	int j;
	push(&L,b);
	mark[b] = 1;
	while(!empty(&L)){
		int x = top(&L);
		pop(&L);
		printf("Duyet %d\n", x);
		List list = neighbors(G,x);
		for(j = 1; j <= list.size; j++){
			int y = element_at(&list,j);
			if(mark[y] != 1){
				mark[y] = 1;
				push(&L,y);
			}
		}
	}
	for(j = 1; j <= G->n; j++){
		if(mark[j] == 0)
			BFS(G, j);
	}
}
