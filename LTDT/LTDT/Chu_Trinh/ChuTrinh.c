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

/*-----------------------------List-------------------------------*/

//khai bao cau truc danh sach
typedef struct{
	int data[MAX_List];
	int size;
}List;

//khoi tao
void MakenullList(List *L){
	L->size = 0;
}

//lay phan tu
int element_at(List *L, int i){
	return L->data[i - 1];
}

//them phan tu vao cuoi danh sach
void appendList(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

//lang gieng
List neigbors(Graph G, int u){
	List L; MakenullList(&L);
	int v;
	for(v = 1; v <= G.n; v++){
		if(adjacent(G, u, v)){
			appendList(&L, v);
		}
	}
	return L;
}

/*-----------------------------ChuTrinh-------------------------------*/

int color[MAX_Vertices];
int has_circle;

void DFS(Graph *G, int u){
	
	//1. To mau dang duyet u
	color[u] = GRAY;
	
	//2. Xet cac dinh ke cua u
	List neigbor = neigbors(*G, u);
	int v;
	for(v = 1; v <= neigbor.size; v++){
		if(color[v] == WHITE){
			DFS(G, v);
		}
		else if(color[v] == GRAY){
			has_circle = 1;
		}
	}
	color[u] = BLACK;
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
	int i;
	for(i = 1; i <= n; i++){
		color[i] = WHITE;
	}
	DFS(&G, 1);
	if(has_circle == 1) printf("YES");
	else printf("NO");
	return 0;
}
