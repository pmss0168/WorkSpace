#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
#define true 1
#define false 0

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
/*List*/
void make_list(List *L)
{
    L->size = 0;
}
void push_back(List *L, Element_Type x)
{
    L->data[L->size] = x;
    L->size++;
}
// List bat dau at i = 0-;
Element_Type element_at(List *L, int i)
{
    return L->data[i - 1];
}
int count_list(List *L)
{
    return L->size;
}
/*End List*/
/*Stack*/
void make_stack(Stack *S)
{
    S->Top = -1;
}
int empty_stack(Stack *S)
{
    return S->Top == -1;
}
void push(Stack *S, Element_Type x)
{
    S->data[++S->Top] = x;
}
Element_Type top(Stack *S)
{
    return S->data[S->Top];
}
void pop(Stack *S)
{
    S->Top--;
}
/*End Stack*/
/*Graph*/
void init_graph(Graph *G, int n)
{
    G->n = n;
    int u, v;
    for (u = 1; u <= G->n; u++)
        for (v = 1; v <= G->n; v++)
            G->data[u][v] = 0;
}
void add_edge(Graph *G, int u, int v)
{
    G->data[u][v] = 1;
}
int degree(Graph *G, int u)
{
    int v, deg = 0;
    for (v = 1; v <= G->n; v++)
        deg += G->data[u][v];
    return deg;
}
int adjacent(Graph *G, int u, int v)
{
    return G->data[u][v] != 0;
}

List neighbors(Graph *G, int u)
{
    List list;
    make_list(&list);
    int v;
    for (v = 1; v <= G->n; v++)
        if (adjacent(G, u, v))
            push_back(&list, v);
    return list;
}
/*Khoi tao bien*/
int on_stack[MAX_VERTICES], num[MAX_VERTICES], min_num[MAX_VERTICES];
int k = 0;
int Check[MAX_VERTICES];
Stack S;
Stack check;
/*Ket thuc khoi tao*/
/*Min*/
int min(int a, int b)
{
    return a < b ? a : b;
}
/*End Min*/
/* Duyệt đồ thị bắt đầu từ đỉnh x */
void strong_connect(Graph *G, int x)
{
    num[x] = min_num[x] = k;
    k++;
    push(&S, x);
    on_stack[x] = 1;
    List list = neighbors(G, x);
    int j;
    /* Xét các đỉnh kề của nó */
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
        if (num[y] < 0)
        {
            strong_connect(G, y);
            min_num[x] = min(min_num[x], min_num[y]);
        }
        else if (on_stack[y])
            min_num[x] = min(min_num[x], num[y]);
    }
    // printf("min_num[%d] = %d\n", x, min_num[x]);
    if (num[x] == min_num[x])
    {
        // printf("%d la dinh khop.\n", x);
        push(&check, x);
        int w;
        do
        {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
        } while (w != x);
    }
}
void Tarjan(Graph *G)
{
    int v;
    for (v = 1; v <= G->n; v++)
    {
        num[v] = -1;
        on_stack[v] = 0;
    }
    k = 1;
    make_stack(&S);
    make_stack(&check);
    for (v = 1; v <= G->n; v++)
    {
        if (num[v] == -1)
            strong_connect(G, v);
    }
}
int main(int argc, char const *argv[])
{
    Graph G;
    int n, m, e, u, v;
    freopen("dothi.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    Tarjan(&G);
    printf("%d", check.Top + 1);
    return 0;
}
