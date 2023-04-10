#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
	int n, m; //n so dinh, m so cung
	//ma tran dinh - cung
	int A[MAX_VERTICES][MAX_EDGES];
} Graph;

//Khoi tao do thi G co n dinh va m cung
void init_graph(Graph *G, int n, int m){
	int i, j;
	G->n = n;
	G->m = m;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			G->A[i][j] = 0;
}

//Them cung e = (x,y) vao do thi G
void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e] = 1; //x lien thuoc voi e
	G->A[y][e] = 1; //y lien thuoc voi e 
}

//Kiem tra y co ke voi x khong
int adjacent(Graph *G, int x, int y){
	int e;
	for(e = 1; e <= G->m; e++){
		if(G->A[x][e] == 1 && G->A[y][e] == 1)
			return 1; 
	}
	return 0;
}

//Tinh bac cua dinh x: deg(x)
int degree(Graph *G, int x){
	int e, deg = 0;
	for(e = 1; e <= G->m; e++){
		if(G->A[x][e] == 1)
			deg++;
	}
	return deg;
}

//Ham main
int main(){
	Graph G;
	int n = 4, m =5, v;
	init_graph(&G,n,m);
	add_edge(&G,1,1,2);
	add_edge(&G,2,1,3);
	add_edge(&G,3,1,3);
	add_edge(&G,4,3,4);
	add_edge(&G,5,1,4);
	
	for(v = 1; v <= n; v++)
		printf("deg(%d) = %d\n",v,degree(&G,v));
	return 0;
}
