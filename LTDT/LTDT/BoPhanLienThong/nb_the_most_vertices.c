#include<stdio.h>
#define Max_G 50
#define Max_L 50
#define E_R 10

/*---------------------------------------------Graph---------------------------------------------*/

typedef struct{
	int A[Max_G][Max_G];
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


/*---------------------------------------------/Graph---------------------------------------------*/


/*---------------------------------------------List---------------------------------------------*/

typedef struct{
	int A[Max_L];
	int size;
}List;

void makenullList(List *L){
	L->size = 0;
}

void appendList(List *L, int element){
	L->A[L->size] = element;
	L->size = L->size + 1;
}

int element_at(List L, int index){
	return L.A[index-1];
}

List Neighbours(Graph G, int u){
	List L;
	makenullList(&L);
	int v;
	for(v = 1; v <= G.n; v++){
		if(G.A[u][v] != 0){
			appendList(&L, v);
		}
	}
	return L;
}
/*---------------------------------------------/List---------------------------------------------*/


/*---------------------------------------------DFS_DQ---------------------------------------------*/

List A[E_R];
List L;
int mark[Max_G];

void DFS_DQ(Graph *G, int s){
	if(mark[s] == 1){
		return;
	}
	appendList(&L, s);
	mark[s] = 1;
	List list = Neighbours(*G, s);
	int i, v;
	for(i = 1; i <= list.size; i++){
		v = element_at(list, i);
		DFS_DQ(G, v);
	}
}

int main(){
	Graph G;
	int n, m;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i, k;
	for(i = 1; i <= n; i++){
		mark[i] = 0;
	}
	int max = 0, index;
	
	for(i = 1; i <= n; i++){
		if(mark[i] == 0){
			makenullList(&A[i-1]);
			DFS_DQ(&G, i);
			if(A[i-1].size > max){
				max = A[i-1].size;
				index = i-1;
			}
		}
		for(i = 1; i <= A[index].size; i++){
			v = element_at(&A[index], i);
			printf("%d ", v);
		}
	}
	return 0;
}
