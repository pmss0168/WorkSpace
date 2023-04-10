#include<stdio.h>
#define Max_G 50
#define Max_S 50
#define Max_L 50

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
	G->A[v][u] = 1;
}

int adjacent(Graph *G, int u, int v){
	return G->A[u][v] != 0;
}

/* --------------------------------------End Graph-------------------------------------- */



/* --------------------------------------Start List-------------------------------------- */

typedef struct{
	int A[Max_L];
	int n;
}List;

void MakenullList(List *L){
	L->n = 0;
}

int element_at(List L, int index){
	return L.A[index-1];
}

void appendList(List *L, int x){
	L->A[L->n] = x;
	L->n = L->n + 1;
}

List Neighbours(Graph G, int s){
	List list;
	MakenullList(&list);
	int v;
	for(v = 1; v <= G.n; v++){
		if(adjacent(&G, s, v)){
			appendList(&list, v);
		}
	}
	return list;
}

/* --------------------------------------End List-------------------------------------- */



/* --------------------------------------Start Stack-------------------------------------- */

typedef struct{
	int A[Max_S];
	int Top_idx;
}Stack;

void MakenullStack(Stack *S){
	S->Top_idx = Max_S;
}

int isEmptyStack(Stack S){
	return S.Top_idx == Max_S;
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


/* --------------------------------------Start DFS-------------------------------------- */

List DFS(Graph *G, int s){
	Stack S; MakenullStack(&S);
	List L; MakenullList(&L);
	int mark[Max_G];
	int i;
	for(i = 1; i <= G->n; i++){
		mark[i] = 0;
	}
	Push(&S, s);
	int u;
	while(!isEmptyStack(S)){
		u = Top(S); Pop(&S);
		if(mark[u] == 1){
			continue;
		}
		appendList(&L, u);
		mark[u] = 1;
		List list = Neighbours(*G, u);
		int k, v;
		for(k = 1; k <= list.n; k++){
			v = element_at(list, k);
			if(mark[v] == 0){
				Push(&S, v);
			}
		}
	}
	return L;
}


/* --------------------------------------Start main-------------------------------------- */

int main(){
	Graph G;
	int n, m;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int i, u, v;
	for(i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int mark[Max_G];
	for(i = 1; i <= n; i++){
		mark[i] = 0;
	}
	int j, k;
	for(j = 1; j <= n; j++){
		if(mark[j] == 0){
			List list = DFS(&G, j);
			for(k = 1; k <= list.n; k++){
				v = element_at(list, k);
				printf("%d\n", v);
				mark[v] = 1;
			}
		}
	}
	return 0;
}

/* --------------------------------------End main-------------------------------------- */
