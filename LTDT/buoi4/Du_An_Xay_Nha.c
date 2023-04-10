#include<stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 500
#define INFINITY 999999

// Graph
typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph *G,int n){
	int i,j;
	G->n=n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j]=0;
}
void add_edge(Graph *G,int x,int y){
	G->A[x][y]=1;
	//G->A[y][x]=w;
}
int adjacent(Graph *G,int x,int y){
	return G->A[x][y]!=0;
}

// List
typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null(List *L){
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
	return L->size >0;
}
List neighbors(Graph *G,int x){
	int y;
	List L;
	make_null(&L);
	for(y=1; y<=G->n; y++)
		if(adjacent(G,x,y))
			push_back(&L,y);
	return L;}
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int min(int a,int b){
	if(a<b) return a;
	else return b;
}

int d[MAX_VERTICES],rank[MAX_VERTICES], t[MAX_VERTICES],T[MAX_VERTICES],dn[MAX_VERTICES];;
void ranking(Graph *G,List *L){
	int x,i,u,v;
	List S0,S1;
	for(u=1; u<=G->n; u++){
		d[u]=0;}
	for(x=1; x<=G->n; x++){
		for(u=1; u<=G->n; u++){
			if(G->A[x][u]!=0){
				d[u]++;
				//printf("%d %d\n",u,d[u]);
			}	
		}
	}	
	make_null(&S0);
	for(u=1; u<=G->n; u++){
		if(d[u]==0)
			push_back(&S0,u);
		//	push_back(L,u);
	} 
	int k;
	make_null(L);
	k=1;
	while(S0.size >0){
		make_null(&S1);
	for(i=1; i<=S0.size; i++){
		u=element_at(&S0,i);
		rank[u]=k;
		push_back(L,u);
		int a;
		for(a=1; a<=G->n; a++)
			if(adjacent(G,u,a)){
				d[a]--;
				if(d[a]==0)
					push_back(&S1,a);
				}
			}
		S0=S1;
		k++;
		}	
//tính t[u]
	t[G->n+1]=0;
	for(i=2; i<=L->size; i++){
		int u=element_at(L,i);
//	printf("%d\n",u);
		t[u]=0;
		for(v=1; v<=G->n+2; v++){
			if(G->A[v][u]>0)
				t[u]=max(t[u],t[v]+dn[v]);
		}
	}
}	


int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	int n,u,v;
	List L;
	scanf("%d",&n);
	init_graph(&G,n+2);
	dn[n+1]=0;
	for(u=1; u<=n; u++){
		scanf("%d",&dn[u]);
	do{
		scanf("%d",&v);
		if(v!=0)
			add_edge(&G,v,u);
		}while(v>0);}
		int i;
	int degn,degr,j;
	for(i=1; i<=n; i++){
		degn=0;
		for(j=1; j<=n; j++){
			if(G.A[j][i]>0){
			degn++;
			}
		}
		if(degn==0){
			add_edge(&G,n+1,i);
		}
	}
	for(i=1; i<=n; i++){
		degr=0;
		for(j=1; j<=n; j++){
			if(adjacent(&G,i,j)){
			degr++;
		}
	}
	if(degr==0){
		add_edge(&G,i,n+2);
	}
	}
	ranking(&G,&L);
	T[n+2]=t[n+2];
   for(j=L.size-1; j>=1; j--){
		int u=element_at(&L,j);
//	printf("%d\n",u);
		T[u]=9999999;
		for(v=1; v<=n+2; v++){
			if(G.A[u][v]>0)
				T[u]=min(T[u],T[v]-dn[u]);	
		}
	}	
//	T[n+2]=t[n+2];
	printf("%d\n",t[n+2]);
	for(i=1; i<=n+2; i++){
		printf("%d-%d\n",t[i],T[i]);
	}
return 0;
}

