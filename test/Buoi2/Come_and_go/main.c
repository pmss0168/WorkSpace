#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
#define T 1
#define F 0
#define NONE -1

typedef int Element_Type;
typedef struct
{
    int n;
    int data[MAX_VERTICES][MAX_VERTICES];
} Graph;
typedef struct
{
    int size;
    Element_Type data[MAX_ELEMENTS];
} List;
typedef struct
{
    int Top;
    Element_Type data[MAX_ELEMENTS];
} Stack;

void make_list(List *L)
{
    L->size = 0;
}
void push_back(List *L, Element_Type x)
{
    L->data[L->size] = x;
    L->size++;
}
Element_Type element_at(List *L, int i)
{
    return L->data[i - 1];
}
int count_list(List *L)
{
    return L->size;
}

void make_stack(Stack *S)
{
    S->Top = -1;
}
void push(Stack *S, Element_Type x)
{
    S->data[++S->Top] = x;
}

void pop(Stack *S)
{
    S->Top--;
}
Element_Type top(Stack *S)
{
    return S->data[S->Top];
}
int empty(Stack *S)
{
    return S->Top == -1;
}

void init_graph(Graph *G, int n)
{
    G->n = n;
    int u, v;
    for (u = 1; u <= G->n; u++)
        for (v = 1; v <= G->n; v++)
            G->data[u][v] = 0;
}
void add_edge(Graph *G, int u, int v, int p)
{
    if (p != 1)
    {
        G->data[u][v] = 1;
        G->data[v][u] = 1;
    }
    else
        G->data[u][v] = 1;
}
int adjacent(Graph *G, int u, int v)
{
    return G->data[u][v] != 0;
}
List neighbors(Graph *G, int u)
{
    int v;
    List list;
    make_list(&list);
    for (v = 1; v <= G->n; v++)
        if (adjacent(G, u, v))
            push_back(&list, v);
    return list;
}
int num[MAX_VERTICES], min_num[MAX_VERTICES], on_stack[MAX_VERTICES];
int k;
Stack S;
Stack C;
int min(int a, int b)
{
    return a < b ? a : b;
}
void strong_connect(Graph *G, int u)
{
    num[u] = min_num[u] = k;
    k++;
    push(&S, u);
    on_stack[u] = T;
    List list = neighbors(G, u);
    int j;
    for (j = 1; j <= list.size; j++)
    {
        int v = element_at(&list, j);
        if (num[v] < 0)
        {
            strong_connect(G, v);
            min_num[u] = min(min_num[u], min_num[v]);
        }
        else if (on_stack[v])
            min_num[u] = min(min_num[u], num[v]);
    }
    if (num[u] == min_num[u])
    {
        push(&C, u);
        int x;
        do
        {
            x = top(&S);
            pop(&S);
            on_stack[x] = F;
        } while (x != u);
    }
}
void Tarjan(Graph *G)
{
    int v;
    for (v = 1; v <= G->n; v++)
    {
        num[v] = NONE;
        on_stack[v] = F;
    }
    k = 1;
    make_stack(&S);
    make_stack(&C);
    for (v = 1; v <= G->n; v++)
    {
        if (num[v] == NONE)
            strong_connect(G, v);
    }
}
int Check(Graph *G)
{
    Tarjan(G);
    return (C.Top + 1) == 1;
}
int main(int argc, char const *argv[])
{
    Graph G;
    int n, m, u, v, p, e;
    freopen("dothi.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &p);
        add_edge(&G, u, v, p);
    }
    if (Check(&G))
        printf("OKIE");
    else
        printf("NO");
    return 0;
}
