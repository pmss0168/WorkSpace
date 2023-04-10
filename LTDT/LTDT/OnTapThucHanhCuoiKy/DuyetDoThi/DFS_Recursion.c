#include<stdio.h>
#define MaxN 100

/*-----------------------------------Graph-----------------------------------*/

typedef struct{
	int A[MaxN][MaxN];
	int n;
}Graph;

void init_Graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
	G->A[v][u] = 1;
}

/*-----------------------------------/Graph-----------------------------------*/


/*-----------------------------------List-----------------------------------*/

typedef struct{
	int A[MaxN];
	int size;
}List;

void MakenullList(List *L){
	L->size = 0;
}

void appendList(List *L, int x){
	L->A[L->size] = x;
	L->size++;
}

int element_at(List L, int i){
	return L.A[i-1];
}

List Neighbours(Graph *G, int u){
	List L;
	MakenullList(&L);
	int i;
	for(i = 1; i <= G->n ;i++){
		if(G->A[u][i] != 0){
			appendList(&L, i);
		}
	}
	return L;
}

/*-----------------------------------/List-----------------------------------*/


/*-----------------------------------DFS_Recursion-----------------------------------*/

int mark[MaxN];
List L;

void DFS_Recursion(Graph *G, int s){
	if(mark[s] == 1){
		return;
	}
	mark[s] = 1;
	appendList(&L, s);
	List lst = Neighbours(G, s);
	int j, v;
	for(j = 1; j <= lst.size; j++){
		v = element_at(lst, j);
		if(mark[v] == 0){
			DFS_Recursion(G, v);
		}
	}
}


int main(){
	Graph G;
	int n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i;
	for(i = 1; i <= n; i++){
		mark[i] = 0;
	}
	MakenullList(&L);
	for(i = 1; i <= n; i++){
		if(mark[i] == 0){
			DFS_Recursion(&G, i);
		}
	}
	for(i = 1; i <= n; i++){
		int v = element_at(L, i);
		printf("%d ", v);
	}
	return 0;
}
