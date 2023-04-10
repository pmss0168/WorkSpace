#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define MAX_VERTICES 100

typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;


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
int mark[MAX_VERTICES];
void traversal(Graph* G, int x) {
	
	if (mark[x] == 1)
		return;
	
	printf("Duyet %d\n", x);
	mark[x] = 1; 
	List list = neighbors(G, x);
	int j;
	for (j = 1; j <= list.size; j++) {
		int y = element_at(&list, j);
		traversal(G, y);
	}
}
void DFS(Graph* G) {
	int j;
	for (j = 1; j <= G->n; j++)
		mark[j] = 0;
	traversal(G, 1);
}
