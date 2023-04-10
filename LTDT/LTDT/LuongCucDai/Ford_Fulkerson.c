#include<stdio.h>

//Cac bien ho tro
#define MAXN 100
#define NO_EDGE 0
#define oo 9999999

typedef struct{
	int C[MAXN][MAXN];
	int F[MAXN][MAXN];
	int n;
}Graph;

void init_Graph(Graph *G, int n){
	G->n = n;
}
typedef struct{
	int dir; // +1: +, -1: -, 0: chua co nhan
	int p; // dinh truoc
	int sigma;
}Label;

Label lablels[MAXN];

/*-----------------------------Hang Doi-----------------------------*/

//khai bao cau truc hang doi
typedef struct{
	int A[MAXN];
	int Front, Rear;
}Queue;

//khoi tao hang doi
void makenullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

//kiem tra hang doi rong
int emptyQueue(Queue Q){
	return Q.Front == -1;
}

//kiem tra hang doi day
int fullQueue(Queue Q){
	return Q.Rear - Q.Front + 1 == MAXN;
}

//phan tu dau hang doi
int Front(Queue Q){
	return Q.A[Q.Front];
}
//them phan tu vao hang doi
void EnQueue(Queue *Q, int x){
	if(!fullQueue(*Q)){
		if(emptyQueue(*Q)){
			Q->Front = 0;
		}
		Q->Rear = Q->Rear + 1;
		Q->A[Q->Rear] = x;
	}
}

//xoa phan tu ra khoi hang doi
void DeQueue(Queue *Q){
	if(!emptyQueue(*Q)){
		Q->Front = Q->Front + 1;
		if(Q->Front > Q->Rear){
			makenullQueue(Q);
		}
	}
}

int min(int x, int y){
	return x > y ? x : y;
}
/*----------------------------------------Cac cong viec can lam cua thuat toan---------------------------------------*/

//Khoi tao tat ca cac luong thuc te = 0
void init_flow(Graph *G){
	int u, v;
	for(u = 1; u <= G->n; u++){
		for(v = 1; v <= G->n; v++){
			G->F[u][v] = 0;
		}
	}
}

Label labels[MAXN];

//FordFullkerson
int FordFullkerson(Graph *G, int s, int t){
	//I. Khoi tao luong = 0
	init_flow(G);
	int max_flow = 0;
	
	//II. lap
	Queue Q;
	do{
		// - buoc 1 - xoa nhan va gan nhan dinh s
		//1.1 xoa tat ca cac nhan cu
		int u;
		for(u = 1; u <= G->n; u++){
			labels[u].dir = 0;
		}
		
		//1.2 Gan nhan s: (+, s, oo)
		labels[s].dir = +1;
		labels[s].p = s;
		labels[s].sigma = oo;
		
		//1.3 Khoi tao Q rong va dua S vao Q
		makenullQueue(&Q);
		EnQueue(&Q, s);
		
		// - buoc 2 - lap gan nhan cho cac dinh tim duong tang luong
		int found = 0;
		while(!emptyQueue(Q)){
			//2.1 lay 1 dinh trong Q ra, goi no la u
			u = Front(Q); DeQueue(&Q);
			
			//2.2 Xet gan nhan cho cac dinh ke voi u: cung thuan
			int v;
			for(v = 1; v <= G->n; v++){
				if(G->C[u][v] != NO_EDGE &&
				   labels[v].dir == 0 &&
				   G->F[u][v] < G->C[u][v]){
				   	
				   	labels[v].dir = +1; //cung thuan
				   	labels[v].p = u;
				   	labels[v].sigma = min(labels[u].sigma, G->C[u][v] - G->F[u][v]);
				   	EnQueue(&Q, v);
				}
			}
			
			//2.3 Xet nhan cho cac dinh di den u: cung nghich
			int x;
			for(x = 1; x <= G->n; x++){
				if(G->C[x][u] != NO_EDGE &&
				   labels[x].dir == 0 &&
				   G->F[x][u] > 0){
				   	
				   	labels[x].dir = -1; //cung nghich
				   	labels[x].p = u;
				   	labels[x].sigma = min(labels[x].sigma, G->F[x][u]);
				   	EnQueue(&Q, x);
				}
			}
			
			//2.4 neu t duoc gan nhan => tim duoc duong tang luong
			if(labels[t].dir != 0){
				found = 1;
				break;
			}
			
			//2.5 tang luong
			if(found == 1){
				//buoc 3 - tang luong
				int sigma = labels[t].sigma; // Luong luong tang them
				
				//3.1 cap nhat luong cua cac cung tren duong tang luong
				u = t;
				while(u != s){
					int p = labels[u].p;
					if(labels[u].dir > 0) // tang luong
					{
						G->F[p][u] = G->F[p][u] + sigma;
					}
					else
					{
						G->F[u][p] = G->F[u][p] - sigma;
					}
					u = p;
				}
				//3.2 Tang gia tri luong tren mang
				max_flow = max_flow + sigma;
			}
			else break; //thoat vong lap
		}
		
	} while(1);
	return max_flow;
}

int main(){
	Graph G;
	int n, m, u, v, e, c;
	freopen("dt.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_Graph(&G, n);
	
	//Doc truc tiep cac cung vao ma tran trong so khong can ham add_edge()
	for(e = 0; e < m; e++){
		scanf("%d%d%d", &u, &v, &c);
		G.C[u][v] = c;
	}
	int max_flow = FordFullkerson(&G, 1, n);
	printf("Max flow: %d\n", max_flow);
	return 0;
}
