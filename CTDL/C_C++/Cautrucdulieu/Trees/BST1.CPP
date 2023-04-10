#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void preOrder(Tree T)
{
    if (!emptyTree(T))
    {
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}
void inOrder(Tree T)
{
    if (!emptyTree(T))
    {
        inOrder(T->Left);
        printf("%d ", T->Data);
        inOrder(T->Right);
    }
}
void postOrder(Tree T)
{
    if (!emptyTree(T))
    {
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%d ", T->Data);
    }
}
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
Tree createTree(int x, Tree l, Tree r)
{
    Tree N;
    N = (Tree)malloc(sizeof(Node));
    N->Data = x;
    N->Left = l;
    N->Right = r;
    return N;
}
int t = 0;
struct Node *createNode(DataType x)
{
    Tree T;
    T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int findMax(Tree T)
{
    if (!emptyTree(T))
    {
        return max(T->Data, max(findMax(T->Left), findMax(T->Right)));
    }
    else
    {
        return 0;
    }
}
Tree findElement(DataType x, Tree T)
{
    if (!emptyTree(T))
    {
        if (T->Data == x)
            return T;
        T = findElement(x, T->Left);
        if (T != NULL)
            return T;
        else
        {
            T = findElement(x, T->Right);
            return T;
        }
    }
    return NULL;
}
int getHeight(Tree T)
{
    if (T != NULL)
    {
        return 1 + max(getHeight(T->Left), getHeight(T->Right));
    }
    return 0;
}
int getDiameter(Tree T, int *Diameter)
{
    if (emptyTree(T))
    {
        return -1;
    }
    else
    {

        // int a = getDiameter(T->Left, Diameter);
        // int b = getDiameter(T->Right, Diameter);
        // if (a > b)
        // {
        //     *Diameter = max(*Diameter, a + 1);
        //     return a + 1;
        // }
        // *Diameter = max(*Diameter, b + 1);
        // return b + 1;

        int lheight = getHeight(T->Left);
        int rheight = getHeight(T->Right);
        int ldiameter = getDiameter(T->Left, Diameter);
        int rdiameter = getDiameter(T->Right, Diameter);
        *Diameter = max(lheight + rheight + 1, max(ldiameter, rdiameter));
        return max(lheight + rheight + 1, max(ldiameter, rdiameter));
    }
}
int getFullNodes(Tree T)
{
    if (!emptyTree(T))
    {
        return (T->Left != NULL && T->Right != NULL) + (getFullNodes(T->Left) + getFullNodes(T->Right));
    }
    return 0;
}
void swap(Tree *L, Tree *R)
{
    Tree temp;
    makenullTree(&temp);
    temp = *R;
    *R = *L;
    *L = temp;
}
Tree convertTree(Tree T)
{
    if (!emptyTree(T))
    {
        swap(&T->Left, &T->Right);
        convertTree(T->Left);
        convertTree(T->Right);
    }
    return T;
}
int isMirrors(Tree T1, Tree T2)
{
    if (emptyTree(T1) && emptyTree(T2))
        return true;
    else
    {
        if (T1 && T2 && T1->Data == T2->Data)
        {
            return (isMirrors(T1->Left, T2->Right) && (isMirrors(T1->Right, T2->Left)));
        }
        else
            return false;
    }
}
Tree getMax(Tree T)
{
    if (T == NULL)
        return NULL;
    if (T->Right == NULL)
        return T;
    return getMax(T->Right);
}
Tree getPrevious(int x, Tree T)
{
    Tree P = T, pocesstor = NULL;
    while (P != NULL)
    {
        if (P->Data == x)
        {
            if (P->Left == NULL)
                return pocesstor;
            else
                return getMax(P->Left);
        }
        else if (P->Data > x)
        {
            P = P->Left;
        }
        else
        {
            pocesstor = P;
            P = P->Right;
        }
    }
    return NULL;
}
//=====================================================
void printArray(int path[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d", path[i]);
    printf("\n");
}
void insertNode(int x, Tree *pT)
{
    (*pT)->Data = x;
    (*pT)->Left = NULL;
    (*pT)->Right = NULL;
}
Tree rightSibling(int x, Tree T)
{
    if (T != NULL)
    {
        if (T->Left->Data == x)
        {
            if (T->Right != NULL)
                return T->Right;
            else
                return NULL;
        }
        if (T->Data > x)
            return rightSibling(x, T->Left);
        if (T->Data < x)
            return rightSibling(x, T->Right);
    }
    return NULL;
}
//========================================ABDECF DBEAFC
int main(int argc, char const *argv[])
{
    Tree T = NULL;
    Tree p;
    int x;

    insertNode(27, &T);
    insertNode(12, &T);
    insertNode(40, &T);
    insertNode(4, &T);
    insertNode(20, &T);
    insertNode(34, &T);
    insertNode(30, &T);
    insertNode(50, &T);
    x = 12;

    p = rightSibling(x, T);
    if (p == NULL)
        printf("Anh em ruot phai khong co hoac khong hop le");
    else
        printf("Nut anh em ruot phai la %d", p->Data);

    return 0;
}
