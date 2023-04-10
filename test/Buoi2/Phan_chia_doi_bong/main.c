#include <stdio.h>
#include <stdlib.h>
/*Dat gia tri hang so cho cau truc do thi va cau truc list*/
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
/*Cai dat mau mat dinh*/
#define White 0
#define Black 1
#define Nocolor -1
/*Dinh dang kieu du lieu cuc bo*/
typedef int Element_Type;
/*Khai bao cau truc*/
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
/*Vi tri bat dau o i = 1*/
Element_Type element_at(List *L, int i)
{
    return L->data[i - 1];
}
int count_list(List *L)
{
    return L->size;
}
/*Ket thuc list*/
/*Graph bat dau*/
void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->data[i][j] = 0;
}
void add_edge(Graph *G, int x, int y)
{
    G->data[x][y] = 1;
}
int adjacent(Graph *G, int x, int y)
{
    return G->data[x][y] != 0;
}
int degree(Graph *G, int x)
{
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        deg += G->data[x][y];
    return deg;
}
List neighbors(Graph *G, int x)
{
    int y;
    List list;
    make_list(&list);
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y))
            push_back(&list, y);
    return list;
}
int color[MAX_VERTICES];
int Checkpass;
void colorize(Graph *G, int x, int c)
{
    if (color[x] == Nocolor)
    {
        color[x] = c;
        List list = neighbors(G, x);
        int i;
        for (i = 1; i <= list.size; i++)
        {
            int y = element_at(&list, i);
            colorize(G, y, !c);
        }
    }
    else
    {
        if (color[x] != c)
            Checkpass = 1;
    }
}
int is_bipartiteGraph(Graph *G)
{
    int i = 1;
    for (i = 1; i <= G->n; i++)
        color[i] = Nocolor;
    Checkpass = 0;
    colorize(G, 1, Black);
    return !Checkpass;
}
int main(int argc, char const *argv[])
{
    Graph G;
    int n, m, u, v, e;
    freopen("dothi.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    if (!is_bipartiteGraph(&G))
        printf("IMPOSSIBLE");
    else
    {
        for (e = 1; e <= G.n; e++)
            if (color[e] == Black)
                printf("%d ", e);
        printf("\n");
        for (e = 1; e <= G.n; e++)
            if (color[e] == White)
                printf("%d ", e);
    }
    return 0;
}
