#include <stdio.h>
#define Max_Vertices 20
#define Max_lenght 20
#define Max_Element 40
typedef struct
{
    int A[Max_Vertices][Max_Vertices];
    int n;
} Graph;

typedef struct
{
    int data[Max_lenght];
    int size;
} List;

// khoi tao danh sach rong
void make_null(List *L)
{
    L->size = 0;
}

// them 1 phan tu vao cuoi danh sach
void push_back(List *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}

// lay 1 phan tu (dinh) trong danh sach tai vi tri i
int element_at(List *L, int i)
{
    return L->data[i - 1];
}

// tim lang gieng cua dinh x
List neighbors(Graph *G, int x)
{
    List L;
    int i;
    make_null(&L);
    for (i = 1; i <= G->n; i++)
        if (G->A[x][i] != 0)
        {
            push_back(&L, i);
        }
    return L;
}
// khoi tao do thi
void init_Graph(Graph *G, int n)
{
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            G->A[i][j] = 0;
        }
}
// them cung
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] += 1;
    G->A[y][x] += 1;
}
// kiem tra lang gieng
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}
// Tinh bac cua dinh x
int degree(Graph *G, int x)
{
    int deg = 0, i;
    for (i = 1; i <= G->n; i++)
        if (G->A[i][x] == 1)
            deg++;
    return deg;
}

typedef struct
{
    int u, p;
} ElementType;

typedef struct
{
    ElementType data[Max_Element];
    int size;
} Stack;

// khoi tao ngan xep rong
void make_null_stack(Stack *stack)
{
    stack->size = 0;
}
// them 1 phan tu vao ngan xep
void push_stack(Stack *stack, ElementType x)
{
    stack->data[stack->size] = x;
    stack->size++;
}

// lay 1 phan tu trong stack
ElementType top(Stack *stack)
{
    return stack->data[stack->size - 1];
}

// xoa 1 phan tu stack
void pop(Stack *stack)
{
    stack->size--;
}

// kiem tra Stack co rong hay ko
int empty(Stack *stack)
{
    return stack->size == 0;
}
int mark[Max_Vertices];
int parent[Max_Vertices];
// duyet theo chieu sau
void DFS(Graph *G, int s)
{
    Stack S;
    make_null_stack(&S);

    ElementType pair;
    pair.u = s;
    pair.p = 0;
    push_stack(&S, pair);
    while (!empty(&S))
    {
        pair = top(&S);
        pop(&S);
        int u = pair.u, p = pair.p;
        if (mark[u] != 0)
            continue;
        //		printf("Duyet: %d\n", u);
        mark[u] = 1;
        parent[u] = p;
        int v;
        for (v = 1; v <= G->n; v++)
        {
            if (adjacent(G, u, v))
            {
                pair.u = v;
                pair.p = u;
                push_stack(&S, pair);
            }
        }
    }
}

int main()
{
    Graph G;
    int i, j, n, m;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    int u, v, e;
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (u = 1; u <= G.n; u++)
        mark[u] = 0;
    int s;

    DFS(&G, 1);

    for (u = 1; u <= G.n; u++)
        printf("%d %d\n", u, parent[u]);
    return 0;
}