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

int check_member(List L, int s){
	int i, v;
	for(i = 1; i <= L.size; i++){
		v = element_at(L, i);
		if(v == s) return 1;
	}
	return 0;
}

int mark[Max_G];
List L;
int nb_conect_vertices;

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
	int n, m, s;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	scanf("%d", &s);
	
	int i, k;
	for(i = 1; i <= n; i++){
		mark[i] = 0;
	}
	makenullList(&L);
	
	for(i = 1; i <= n; i++){
		if(mark[i] == 0){
			DFS_DQ(&G, i);
			if(check_member(L, s)){
				for(k = 1; k <= L.size; k++){
					v = element_at(L, k);
					printf("%d ", v);
				} 
			}
			makenullList(&L);
		}
	}
	
	return 0;
}
