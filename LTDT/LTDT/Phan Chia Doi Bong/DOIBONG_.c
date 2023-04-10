#include<stdio.h>
#define MAX_Vertices 20
#define NO_COLOR 0
#define BLUE 1
#define RED 2

/*-----------------------------Graph-------------------------------*/
//cau truc do thi
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;
}Graph;

//khoi tao do thi
void init_Graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->A[i][j] = 0;
		}
	}
}

//them cung
void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

//kiem tra lien thuoc
int adjacent(Graph G, int u, int v){
	return G.A[u][v] != 0;
}

/*-----------------------------DFS-------------------------------*/
int color[MAX_Vertices];
int conflict;

void corlorize(Graph *G, int u, int c){
	//1.To mau c cho dinh u
	color[u] = c;
	//2.Xet cac dinh ke cua u
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(*G, u, v)){
			if(color[v] == NO_COLOR){
				corlorize(G, v, 3-c);
			}
			else if(color[v] == color[u]){
				conflict = 1;
			}
		}
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
	for(v = 1; v <= n; v++){
		color[v] = NO_COLOR;
	}
	int i;
	for(i = 1; i <= n; i++){
		if(color[i] == NO_COLOR){
			corlorize(&G, i, RED);
		}
	}
	if(conflict == 1) printf("IMPOSSIBLE");
	else{
		int j, k;
		for(j = 1; j <= n; j++){
			if(color[j] == RED){
				printf("%d ", j);
			}
		}
		printf("\n");
		for(k = 1; k <= n; k++){
			if(color[k] == BLUE){
				printf("%d ", k);
			}
		}
	}
	return 0;
}
