#include<stdio.h>
#define MAX_Vertices 20
#define MAX_Stack 20
#define MAX_List 20
#define WHITE 0
#define GRAY 1
#define BLACK 2

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
//**************************danh sach*********************************//

//khai bao cau truc danh sach
typedef struct{
	int data[MAXLength];
	int size;
}List;

//khoi tao danh sach
void MakenullList(List *L){
	L->size = 0;
}

//them phan tu vao sau danh sach
void appendList(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

//lay 1 phan tu trong danh sach
int element_at(List *L, int i){
	return L->data[i-1];
}
/*-----------------------------ChuTrinh-------------------------------*/

int color[MAX_Vertices];
int has_circle;

void DFS(Graph *G, int u){
	
	//1.to mau cho dinh u dang duyet
	color[u] = GRAY;
	
	//2.xet cac dinh ke cua u
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(*G, u, v)){
			if(color[v] == WHITE){
				DFS(G, v);
			}
			else if(color[v] == GRAY){
				has_circle = 1;
			}
		}
	}
	color[u] = BLACK;
}

int main(){
	Graph G;
	int n, m, mark[MAX_Vertices];
	freopen("dothi.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i, j;
	for(i = 1; i <= n; i++){
		color[i] = WHITE;
	}
	for(j = 1; j <= n; j++){
		if(color[j] == WHITE){
			DFS(&G, j);
		}
	}
	for(i = 1; i <= n; i++){
		mark[u] = 0;
	}
	
	return 0;
}
