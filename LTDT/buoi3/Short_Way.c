#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENTS 500
#define MAX_VERTICES 100
#define NO_EDGE -1
#define INFINITY 99999


//GRAPH
typedef int Element_Type;
typedef struct{
	int n;
	Element_Type data[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph *G, int n){
	int u,v;
	G->n = n;
	for(u = 1; u <= G->n; u++)
		for(v = 1; v <= G->n; v++)
			G->data[u][v] = NO_EDGE;
}
void add_edge(Graph *G, int u, int v, int w){
	G->data[u][v] = w;
    G->data[v][u] = w;
}
int degree(Graph *G, int u){
	int j, deg = 0;
	for(j = 1; j <= G->n; j++){
		deg += G->data[u][j];
	}
	return deg;
}
int adjacent(Graph *G, int u, int v){
	return G->data[u][v] != 0;
}
int mark[MAX_VERTICES];
int p[MAX_VERTICES];
int pi[MAX_VERTICES];

void Dijkstra(Graph *G, int s){
	int i,j,it;
	for(i = 1; i <= G->n; i++){
		if(i != s)
		    pi[i] = INFINITY;
		mark[i] = 0;
	}
	pi[s] = 0;
	p[s] = -1; // truoc s khong co dinh nao ca
	for(it = 1; it <= G->n; it++){
		//1.Tim i co mark i = 0 va co pi[i] nho nhat
		int min_pi = INFINITY;
		for(j = 1; j <= G->n; j++)
			if(mark[j] == 0 && pi[j] < min_pi){
				min_pi = pi[j];
				i = j;
			}
		mark[i] = 1;
		//2.Cap nhat pi va p cua cac dinh ke cua i
		for(j = 1; j <= G->n; j++){
			if(G->data[i][j] != NO_EDGE && mark[j] == 0){
				if(pi[i] + G->data[i][j] < pi[j]){
					pi[j] = pi[i] + G->data[i][j];
					p[j] = i;
				}
			}
		}
	}
}

//Main
int main()
{
    freopen("dt.txt", "r", stdin); //Khi n?p b�i nh? b? d�ng n�y.
	Graph G;
	int n, m, u, v, w, e, s, t;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
    scanf("%d%d", &s, &t);
    Dijkstra(&G, s);
//    for (i = 1; i <= G.n; i++)
//		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
// 	if(pi[G.n] == INFINITY)
// 		printf("-1");
// 	else
// 		printf("%d",pi[G.n]);
    printf("%d", pi[t]);
    return 0;  
}
