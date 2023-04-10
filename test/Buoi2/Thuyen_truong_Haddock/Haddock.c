#include <stdio.h>

#define white 0
#define black 1
#define gray 2
#define MAX_VERTICES 20
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
    int n;
    int data[MAX_VERTICES][MAX_VERTICES];
} Graph;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
/* Tao danh sach rong */
void make_null(List *L)
{
    L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1
 */
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List *L)
{
    return L->size;
}
/*****************************************/
/*Cau truc Graph*/

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
    make_null(&list);
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y))
            push_back(&list, y);
    return list;
}
/* Khung chu trinh*/
int color[MAX_VERTICES];
int cycle;

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
            cycle = 1;
            return;
        }
        if (color[y] == white)
            dfs(G, y);
    }
    color[x] = black;
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    int j;
    for (j = 1; j <= G.n; j++)
    {
        color[j] = white;
    }
    cycle = 0;
    dfs(&G, 1);
    if (cycle == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
