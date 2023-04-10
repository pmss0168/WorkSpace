#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int t = 0;
typedef int DataType;
struct Node
{
    DataType Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;

void makenullTree(Tree *pT)
{
    (*pT) = NULL;
}
int emptyTree(Tree T)
{
    return T == NULL;
}
Tree leftChild(Tree n)
{
    if (n != NULL)
        return n->Left;
    else
        return NULL;
}
Tree rightChild(Tree n)
{
    if (n != NULL)
        return n->Right;
    else
        return NULL;
}
int isLeaf(Tree n)
{
    if (n != NULL)
        return (n->Left == NULL) && (n->Right == NULL);
    else
        return 0;
}
// void preOrder(Tree T)
// {
//     if (!emptyTree(T))
//     {
//         printf("%d ", T->Data);
//         preOrder(T->Left);
//         preOrder(T->Right);
//     }
// }
// void inOrder(Tree T)
// {
//     if (!emptyTree(T))
//     {
//         inOrder(T->Left);
//         printf("%d ", T->Data);
//         inOrder(T->Right);
//     }
// }
// void postOrder(Tree T)
// {
//     if (!emptyTree(T))
//     {
//         postOrder(T->Left);
//         postOrder(T->Right);
//         printf("%d ", T->Data);
//     }
// }
int nb_nodes(Tree T)
{
    if (emptyTree(T))
        return 0;
    else
        return 1 + nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}
int nb_leaves(Tree T)
{
    if (emptyTree(T))
        return 0;
    else
    {
        if (isLeaf(T))
            return 1;
        else
            return nb_leaves(leftChild(T)) + nb_leaves(rightChild(T));
    }
}
Tree create2(DataType v, Tree l, Tree r)
{
    Tree N;
    N->Data = v;
    N->Left = l;
    N->Right = r;
    return N;
}
Tree findElement(DataType v, Tree T)
{
    if (emptyTree(T))
        return NULL;
    else
    {
        if (v == T->Data)
            return T;
        else
        {
            if (leftChild(T) != NULL)
                findElement(v, leftChild(T));
            if (rightChild(T) != NULL)
                findElement(v, rightChild(T));
        }
    }
}
//=============Else cap san bien========================================
int findIndex(DataType x, char in[], int star, int end)
{
    int i = star;
    while (i <= end)
    {
        if (x == in[i])
            return i;

        else
            i++;
    }
    return i;
}
//======================Else============================================
// Tree initTree()
// {
//     Tree T;
//     T = NULL;
//     return T;
// }
// int isEmpty(Tree T)
// {
//     return T == NULL;
// }
void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}
void inOrder(Tree T)
{
    if (T != NULL)
    {
        inOrder(T->Left);
        printf("%d ", T->Data);
        inOrder(T->Right);
    }
}
void postOrder(Tree T)
{
    if (T != NULL)
    {
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%d ", T->Data);
    }
}
// Tree createTree(int x, Tree l, Tree r)
// {
//     Tree N;
//     N = (Tree)malloc(sizeof(Node));
//     N->Data = x;
//     N->Left = l;
//     N->Right = r;
//     return N;
// }
// int getHeight(Tree T)
// {
//     if (T != NULL)
//     {
//         int a = getHeight(T->Left);
//         int b = getHeight(T->Right);
//         if (a > b)
//             return (a + 1);
//         return (b + 1);
//     }
//     return -1;
// }
// int getLeaves(Tree T)
// {
//     if (T != NULL)
//     {
//         if ((T->Left == NULL) && (T->Right == NULL))
//             return 1;
//         else
//             return getLeaves(T->Left) + getLeaves(T->Right);
//     }
//     return 0;
// }
Tree createTree(char pre[], char in[], int start, int end)
{
    Tree T;
    if (start > end)
        return NULL;
    if (start == end)
    {
        T = (Tree)malloc(sizeof(Node *));
        T->Data = pre[t];
        t++;
        T->Left = NULL;
        T->Right = NULL;
        return T;
    }
    else
    {
        T = (Tree)malloc(sizeof(Node *));
        T->Data = pre[t];
        t++;
        int inOrderIndex = findIndex(T->Data, in, 0, end);
        T->Left = createTree(pre, in, 0, inOrderIndex - 1);
        T->Right = createTree(pre, in, inOrderIndex + 1, end);
        return T;
    }
}
//========================================ABDECF DBEAFC
int main(int argc, char const *argv[])
{
    Tree T;
    char pre[100], in[100];
    printf("Nhap Pre =");
    fgets(pre, 100, stdin);
    if (pre[strlen(pre) - 1] == '\n')
    {
        pre[strlen(pre) - 1] = '\0';
    }
    printf("Nhap In =");
    fgets(in, 100, stdin);
    if (in[strlen(in) - 1] == '\n')
    {
        in[strlen(in) - 1] = '\0';
    }
    T = createTree(pre, in, 0, strlen(in) - 1);
    printf("Ket qua duyet hau tu: ");
    if (T != NULL)
        postOrder(T);
    return 0;
}
