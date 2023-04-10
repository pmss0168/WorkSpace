#include<stdio.h>
#define INF 99999
#define NO_EDGE -1
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100

// List
typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null_list(List *L){
	L->size=0;
}
void push_back(List *L,ElementType x){
	L->data[L->size]=x;
	L->size++;
}
ElementType element_at(List *L,int i){
	return L->data[i-1];
}
int count_list(List *L){
	return L->size;
}
int empty(List *L){
	return L->size == 0;
}
int check(List L, int x){
    int i;
    for(i=1; i<=L.size; i++)
        if(x==element_at(&L,i))
            return 1;
    return 0;
}
//Graph
typedef struct{
    int u, v;
    int w;
}Edge;
typedef struct{
	int n, m;
	ElementType data[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph* G,int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->data[i][j] = 0;
}
void add_edge1(Graph* G, int u, int v, int w){
	G->data[u][v] += w;
    G->data[v][u] += w;
}
int min(Edge a, Edge b){
    if(((a.u < b.u) || (a.u == b.u)) && (a.v < b.v))
        return 1;
    return 0;
}
void Swap(Edge *a, Edge *b){
    Edge temp;
    temp =  *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(Edge edge[], int n){
    int i, j;
    for(i = 0; i <= n-1; i++)
        for(j = n-1; j > i; j--){
            if(min(edge[j],edge[j-1]))
                Swap(&edge[j], &edge[j-1]);
        }
}


Edge edge[100];
int mark[100];
int cnt = 0;
int distanceFrom(int u, List* L, Graph* G){
    int min_dist = INF;
    int min_v = NO_EDGE;
    int i;
    for(i = 1; i <= L->size; i++){
        int v = element_at(L, i);
        if(G->data[u][v] != 0 && min_dist > G->data[u][v]){
            min_dist = G->data[u][v];
            min_v = v;
        }
    }
    return min_v;
}

int Prim(Graph* G, Graph* T){
    init_graph(T, G->n);
    List L;
    make_null_list(&L);
    int i, u;
    for(i = 1; i < G->n; i++)
        mark[i] = 0;
    push_back(&L,1);
    mark[1] = 1;
    int sum_w = 0;
    for(i = 1; i < G->n; i++){
        int min_dist = INF;
        int min_u, min_v;
        for(u = 1; u <= G->n; u++)
            if(mark[u] == 0){
                int v = distanceFrom(u, &L, G);
                if(v != -1 && G->data[u][v] < min_dist){
                    min_dist = G->data[u][v];
                    min_u = u;
                    min_v = v;
                    edge[cnt].u = v;
                    edge[cnt].v = u;
                    edge[cnt].w = min_dist;
                    cnt++;
                }
            }
        push_back(&L, min_u);
        mark[min_u] = 1;
        add_edge1(T,min_u,min_v,min_dist);
        sum_w += min_dist;
    }
    return sum_w;
}

int main(){
    Graph G, T;
    int n, m, u, v, w, e, i;
    FILE *f = freopen("Prim.txt", "r", stdin);
    scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge1(&G, u, v, w);
	}
    int sum_w = Prim(&G, &T);
    printf("%d\n", sum_w);
    BubbleSort(edge,cnt);
    for(i = 0; i < cnt; i++)
        printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
    return 0;
}