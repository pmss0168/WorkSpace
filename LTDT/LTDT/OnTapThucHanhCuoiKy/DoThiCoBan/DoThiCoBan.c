#include<stdio.h>

typedef struct{
	int u, v;
}Edge;

typedef struct{
	int n, m;
	Edge edges[100];
}Graph;

void init_Graph(Graph *G, int n){
	G->n = n; 
	G->m = 0;
}

void add_edge(Graph *G, int u, int v){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->m++;
}

int degree(Graph *G, int u){
	int deg_u = 0;
	int i;
	for(i = 0; i < G->m; i++){
		if((G->edges[i].u == u || G->edges[i].v == u)){
			deg_u++;
		}
		if((G->edges[i].u == u && G->edges[i].v == u)){
			deg_u++;
		}
	}
	return deg_u;
}

//Cau truc List
typedef struct{
	int A[100];
	int n;
}List;

void MakenullList(List *L){
	L->n = 0;
}

void appendList(List *L , int x){
	L->A[L->n] = x;
	L->n++;
}

int member(List L, int u){
	int i;
	for(i = 0; i < L.n; i++){
		if(L.A[i] == u){
			return 1;
		}
	}
	return 0;
}

List neigbours(Graph *G, int u){
	List L;
	MakenullList(&L);
	int i;
	for(i = 0; i < G->m; i++){
		if((G->edges[i].u == u && G->edges[i].v == u) && !member(L, G->edges[i].v)){
			appendList(&L, G->edges[i].u);
		}
		if(G->edges[i].u == u && !member(L, G->edges[i].v)) appendList(&L, G->edges[i].v);
		if(G->edges[i].v == u && !member(L, G->edges[i].u)) appendList(&L, G->edges[i].u);
	}
	return L;
}

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void SelectionSort(List *L){
	int i, j;
	for(i = 0; i < L->n-1; i++){
		for(j = i + 1; j < L->n; j++){
			if(L->A[j] < L->A[i]){
				swap(&L->A[j], &L->A[i]);
			}
		}
	}
}

int main(){
	Graph G;
	int n, m;
	freopen("dt.txt","r", stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i;
	for(i = 1; i <= n; i++){
		List lst = neigbours(&G, i);
		SelectionSort(&lst);
		int j;
		printf("neighbours(%d) = ", i);
		for(j = 0; j < lst.n; j++){
			printf("%d ", lst.A[j]);
		}
		printf("\n");
	}
	return 0;
}
