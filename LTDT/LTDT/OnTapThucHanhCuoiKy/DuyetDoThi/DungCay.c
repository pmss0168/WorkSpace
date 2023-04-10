#include<stdio.h>
#define Max_List 50
#define Max_Queue 50
#define Max_G 20

/*----------------------------------------------Cau Truc Do Thi----------------------------------------------*/

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

/*----------------------------------------------/Cau Truc Do Thi----------------------------------------------*/




/*----------------------------------------------Cau Truc Danh Sach----------------------------------------------*/

typedef struct{
	int A[Max_List];
	int size;
}List;

void MakenullList(List *L){
	L->size = 0;
}

void appendList(List *L, int x){
	L->A[L->size] = x;
	L->size++;
}

int element_at(List *L, int i){
	return L->A[i-1];
}

List Neigbours(Graph *G, int u){
	List L;
	MakenullList(&L);
	int v;
	for(v = 1; v <= G->n; v++){
		if(G->A[u][v] != 0){
			appendList(&L, v);
		}
	}
	return L;
}

/*----------------------------------------------/Cau Truc Danh Sach----------------------------------------------*/




/*----------------------------------------------Cau Truc Hang Doi----------------------------------------------*/

typedef struct{
	int A[Max_Queue];
	int Front, Rear;
}Queue;

void MakenullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

int emptyQueue(Queue *Q){
	return Q->Front == -1;
}

int fullQueue(Queue *Q){
	return Q->Rear - Q->Front + 1 == Max_Queue;
}

int front(Queue *Q){
	return Q->A[Q->Front];
}

void EnQueue(Queue *Q, int x){
	if(!fullQueue(Q)){
		if(emptyQueue(Q)){
			Q->Front = 0;
		}
		Q->Rear = Q->Rear + 1;
		Q->A[Q->Rear] = x;
	}
}

void DeQueue(Queue *Q){
	if(!emptyQueue(Q)){
		Q->Front = Q->Front + 1;
		if(Q->Front > Q->Rear){
			MakenullQueue(Q);
		}
	}
}

/*----------------------------------------------/Cau Truc Hang Doi----------------------------------------------*/




/*----------------------------------------------Duyet Do Thi (Chieu Rong)----------------------------------------------*/

int mark[Max_G];
int parent[Max_G];

List BFS(Graph *G, int s){
	List L; MakenullList(&L);
	Queue Q; MakenullQueue(&Q);
	EnQueue(&Q, s);
	int u;
	parent[s] = -1;
	while(!emptyQueue(&Q)){
		u = front(&Q); DeQueue(&Q);
		if(mark[u] == 1){
			continue;
		}
		mark[u] = 1;
		appendList(&L, u);
		List lst = Neigbours(G, u);
		int i, v;
		for(i =  1; i <= lst.size; i++){
			v = element_at(&lst, i);
			if(mark[v] == 0){
				EnQueue(&Q, v);
				parent[v] = u;
			}
		}
	}
	return L;
}

/*----------------------------------------------/Duyet Do Thi (Chieu Rong)----------------------------------------------*/


/*----------------------------------------------main----------------------------------------------*/

int main(){
	Graph G;
	int n, m;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 1; e <= m ;e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	int i;
	for(i = 1; i <= n; i++){
		mark[i] = 0;
		parent[i] = 0;
	}
	
	for(i = 1; i <= n; i++){
		if(mark[i] == 0){
			List lst = BFS(&G, i);
			int j;
			for(j = 1; j <= lst.size; j++){
				int v = element_at(&lst, j);
				printf("%d  parent[%d] = %d\n", v, v, parent[v]);
			}
		}
	}
	return 0;
}
