#include<stdio.h>
#define MAX_VERTICES 100
#define INF 99999
#define NO_EDGE 0
#define MAX_ELEMENTS 100

//Stack
typedef struct{
	int data[MAX_ELEMENTS];
	int front, rear;
}Queue;
void make_null_queue(Queue* Q){
	Q->front = 0;
	Q->rear = -1;
}
void enqueue(Queue* Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}
int top(Queue* Q){
	return Q->data[Q->front];
}
void dequeue(Queue* Q){
	Q->front++;
}
int empty(Queue* Q){
	return Q->front > Q->rear;
}
//Graph
typedef struct{
    int C[MAX_VERTICES][MAX_VERTICES];
    int F[MAX_VERTICES][MAX_VERTICES];
    int n;
}Graph;
void init_graph(Graph* G, int n){
    G->n = n;
}
typedef struct{
    int dir;
    int pre;
    int sigma;
}Label;

Label label[MAX_VERTICES];
void init_flow(Graph* G){
    int u, v;
    for(u = 1; u <= G->n; u++)
        for(v = 1; v<= G->n; v++)
            G->F[u][v] = 0;
}
int min(int a, int b){
    return a < b ? a : b;
}
int LuongCucDai(Graph* G, int s, int t){
    init_flow(G);
    int u, v, sum_flow = 0;
    Queue Q;
    do{
        for(u = 1; u <= G->n; u++)
            label[u].dir = 0;
        label[s].dir = 1;
        label[s].pre = s;
        label[s].sigma = INF;
        make_null_queue(&Q);
        enqueue(&Q,s);
        int found = 0;
        while(!empty(&Q)){
            int u = top(&Q);
            dequeue(&Q);
            for(v = 1; v <= G->n; v++){
                if(label[v].dir == 0 && G->C[u][v] != NO_EDGE && G->F[u][v] < G->C[u][v]){
                    label[v].dir = 1;
                    label[v].pre = u;
                    label[v].sigma = min(label[u].sigma, G->C[u][v] - G->F[u][v]);
                    enqueue(&Q,v);
                }
                if(label[v].dir == 0 && G->C[v][u] != NO_EDGE && G->F[v][u] > 0){
                    label[v].dir = -1;
                    label[v].pre = u;
                    label[v].sigma = min(label[u].sigma, G->F[u][v]);
                    enqueue(&Q,v);
                }
            }
            if(label[t].dir != 0){
                found = 1;
                break;
            }
        }
        if(found == 1){
            int x = t;
            int sigma = label[t].sigma;
            sum_flow += sigma;
            while(x != s){
                int u = label[x].pre;
                if(label[x].dir > 0)
                    G->F[u][x] += sigma;
                else
                    G->F[x][u] -= sigma;
                x = u;
            }
        }else
            break;
    }while(1);
    return sum_flow;
}

int main(){
    FILE *f = freopen("Luong_Cuc_Dai.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
    Graph G;
    int n, m, u, v, c ,e;
    scanf("%d%d", &n, &m);
    init_graph(&G,n);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &c);
        G.C[u][v] = c;
    }
    int max_flow = LuongCucDai(&G,1,n);
    printf ("Max flow: %d \n",max_flow);
    printf("X0: ");
    for (e = 1; e <= G.n; e++) {
        if (label[e].dir != 0)
            printf("%d ",e);
    }
    printf("\nY0: ");
    for (e = 1; e <= G.n; e++) {
        if(label[e].dir == 0)
            printf("%d ",e);
    }
    return 0;
}