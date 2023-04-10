#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "List.h"
#define white 0
#define black 1
#define gray 2
#define MAX_VERTICES 100
int color[MAX_VERTICES];
int cycle;
typedef struct
{
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] += 1;
    G->A[y][x] += 1;
}

int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}

int degree(Graph *G, int x)
{
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        deg += G->A[x][y];
    return deg;
}

List neighbors(Graph *G, int x)
{
    int y;
    List list;
    make_null(&list);
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y))
            push_back(&list, y);
    return list;
}
/* Biến hỗ trợ */

/* Duyệt đồ thị bắt đầu từ đỉnh x */
void dfs(Graph *G, int x)
{
    color[x] = gray;
    int j;
    List list = neighbors(G, x);
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
        if (color[y] == gray)
        {
            cycle = 1; /* Tồn tại chu trình */
            return;
        }
        if (color[y] == white)
            dfs(G, y);
    }
    color[x] = black;
}
/* Kiểm tra toàn bộ đồ thị*/
int contains_cycle(Graph *G)
{
    int j;
    for (j = 1; j <= G->n; j++)
    {
        color[j] = white;
    }
    cycle = 0;
    for (j = 1; j <= G->n; j++)
    {
        if (color[j] == white)
            dfs(G, j);
        return cycle;
    }
}