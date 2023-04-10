#include <stdio.h>
#include <stdlib.h>
#include <string>

struct Node
{
    int Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;
Tree initTree()
{
    Tree T;
    T == NULL;
    return T;
}
int isEmpty(Tree T)
{
    return T == NULL;
}

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
