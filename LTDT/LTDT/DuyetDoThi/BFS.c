#include<stdio.h>
#define Max_G 50
#define Max_Q 50
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



/* --------------------------------------Start Queue-------------------------------------- */

typedef struct{
	int A[Max_Q];
	int Front, Rear;
}Queue;

void MakenullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

int isEmptyQueue(Queue Q){
	return Q.Front == -1;
}

int isFullQueue(Queue Q){
	return Q.Rear - Q.Front + 1 == Max_Q;
}

int Front(Queue Q){
	return Q.A[Q.Front];
}

void EnQueue(Queue *Q, int x){
	if(!isFullQueue(*Q)){
		if(isEmptyQueue(*Q)){
			Q->Front = 0;
		}
		Q->Rear = Q->Rear + 1;
		Q->A[Q->Rear] = x;
	}
}

void DeQueue(Queue *Q){
	if(!isEmptyQueue(*Q)){
		Q->Front = Q->Front + 1;
		if(Q->Front > Q->Rear){
			MakenullQueue(Q);
		}
	}
}

/* --------------------------------------End Queue-------------------------------------- */



/* --------------------------------------Start BFS-------------------------------------- */

int Mark[Max_G];
List BFS(Graph *G, int s){
	Queue Q; MakenullQueue(&Q);
	List L; MakenullList(&L);
	int i;
	for(i = 1; i <= G->n; i++){
		Mark[i] = 0;
	}
	EnQueue(&Q, s);
	int u;
	while(!isEmptyQueue(Q)){
		u = Front(Q); DeQueue(&Q);
		if(Mark[u] == 1){
			continue;
		}
		Mark[u] = 1;
		appendList(&L, u);
		List list = Neighbours(*G, u);
		int v, k;
		for(k = 1; k <= list.n; k++){
			v = element_at(list, k);
			if(Mark[v] == 0){
				EnQueue(&Q, v);
			}
		}
	}
	return L;
}

/* --------------------------------------End BFS-------------------------------------- */



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
			List list = BFS(&G, j);
			for(k = 1; k <= list.n; k++){
				v = element_at(list, k);
				printf("%d\n", v);
				mark[v] = 1;
			}
		}
	}
	return 0;
}
