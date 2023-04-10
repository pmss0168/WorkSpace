#include<stdio.h>
#define MAX_N 20

/*----------------------------Graph---------------------------*/

typedef struct{
	int A[MAX_N][MAX_N];
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

void add_edges(Graph *G, int u, int v){
	G->A[u][v] = 1;
}

int adjacent(Graph *G, int u, int v){
	return G->A[u][v] != 0;
}

/*----------------------------Stack---------------------------*/

typedef struct{
	int stack[MAX_N];
	int Top_idx;
}Stack;

void MakenullStack(Stack *S){
	S->Top_idx = MAX_N;
}

int Top(Stack S){
	return S.stack[S.Top_idx];
}

void Push(Stack *S, int x){
	S->Top_idx = S->Top_idx - 1;
	S->stack[S->Top_idx] = x;
}

void Pop(Stack *S){
	S->Top_idx = S->Top_idx + 1;
}
/*----------------------------Taijan---------------------------*/
int min(int x, int y){
	return x < y ? x : y;
}
int num[MAX_N], min_num[MAX_N];
int k;
Stack S;
int on_stack[MAX_N];
int nb_strongconnect;

void SCC(Graph *G, int u){
	
	//1.Danh so u, dua u vao ngan xep S
	num[u] = min_num[u] = k; k++;
	Push(&S, u);
	on_stack[u] = 1;
	
	//2.xet cac dinh ke cua u
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G, u, v)){
			if(num[v] < 0){
				SCC(G, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}else if(on_stack[v] == 1){
				min_num[u] = min(min_num[u], num[v]);
			}
		}
	}
	
	//3. kiem tra u co phai la dinh khop
	if(num[u] == min_num[u]){
		int w;
		nb_strongconnect++;
		do{ // lay cac dinh trong S ra cho den khi gap u
		    w = Top(S);
			Pop(&S);
			on_stack[w] = 0;
		} while(w != u);
	}
}

int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	int e, u, v;
	for(e = 0; e < m; e++){
		scanf("%d%d", &u, &v);
		add_edges(&G, u, v);
	}
	int i;
	for(i = 1; i <= G.n; i++){  //1a.tat ca deu chua duyet
		num[i] = -1;
		min_num[i] = -1;
		on_stack[i] = 0;	
	}
	k = 1;                    //1b.bat dau danh dau
	MakenullStack(&S);        //1c.lam rong ngan xep
	nb_strongconnect = 0;
	SCC(&G, 1);
	printf("%d", nb_strongconnect);
	return 0;
}
