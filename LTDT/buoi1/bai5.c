#include<stdlib.h>
#include<stdio.h>
#define MAX_VERTICES 100
typedef struct {
	int n; //n so dinh
	//ma tran dinh - dinh
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

//Khoi tao do thi G co n dinh
void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->A[i][j] = 0;
}

//Them cung e = (x,y) vao do thi G
void add_edge(Graph *G, int x, int y){
	G->A[x][y] += 1; 
	G->A[y][x] += 1; 
}

//Kiem tra y co ke voi x khong
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

//Tinh bac cua dinh x: deg(x), truong hop da cung
int degree(Graph* G, int x){
	int y, deg = 0;
	for(y = 1; y <= G->n; y++){
		deg += G->A[x][y];
	}
	return deg;
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
