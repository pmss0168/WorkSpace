#include<stdio.h>
#define Max_G 50

/* --------------------------------------Start Graph-------------------------------------- */

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
}

int adjacent(Graph *G, int u, int v){
	return G->A[u][v] != 0;
}

/* --------------------------------------End Graph-------------------------------------- */


/* --------------------------------------Start Stack-------------------------------------- */

typedef struct{
	int A[Max_G];
	int Top_idx;
}Stack;

void makenullStack(Stack *S){
	S->Top_idx = Max_G;
}

int isEmptyStack(Stack S){
	return S.Top_idx == Max_G;
}

int Top(Stack S){
	return S.A[S.Top_idx];
}

void Push(Stack *S, int x){
	S->Top_idx = S->Top_idx - 1;
	S->A[S->Top_idx] = x;
}

void Pop(Stack *S){
	S->Top_idx = S->Top_idx + 1;
}

/* --------------------------------------End Stack-------------------------------------- */


/* --------------------------------------Start Tarjan-------------------------------------- */
int min(int x, int y){
	return x < y ? x : y;
}

int num[Max_G], min_num[Max_G];
int k;
Stack S;
int on_stack[Max_G];
int strong_connected;

void SCC(Graph *G, int u){
	
	//1. Danh so u, dua u vao ngan xep
	num[u] = k; min_num[u] = k; k++;
	Push(&S, u);
	on_stack[u] = 1;
	
	//2. Xet cac dinh ke cua u
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G, u, v)){
			if(num[v] < 0){
				SCC(G, v);
				min_num[u] = min(min_num[u], min_num[v]);
			} else if (on_stack[v] == 1){
				min_num[u] = min(min_num[u], num[v]);
			}
		}
	}
	
	//3.Kiem tra u co phai la dinh khop
	if(num[u] == min_num[u]){
		strong_connected++; // Tim duoc bo phan lien thong manh u -> v .....->u 
		int w;
		do {
			w = Top(S);
			Pop(&S);
			on_stack[w] = 0;
		} while(w != u);
	}
}

int main(){
	Graph G;
	int n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int i, u, v;
	for(i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(i = 1; i <= n; i++){
		num[i] = -1;
		min_num[i] = -1;
		on_stack[i] = 0;
	}
	k = 1;
	makenullStack(&S);
	strong_connected = 0;
	SCC(&G, 1);
	if(strong_connected == 1) printf("strong connected");
	else printf("unconnected");
	return 0;
}