#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElementType;
struct Node
{
    ElementType Elements;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;

//=====Khoi tao phuong thuc========
void makenullList(List *pL)
{
    (*pL) = (List)malloc(sizeof(Node));
    (*pL)->Next = NULL;
}
int emptyList(List L)
{
    return L->Next == NULL;
}
ElementType retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Elements;
}
Position first(List L)
{
    return L;
}
Position endList(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        P = P->Next;
    }
    return P;
}
Position next(Position P, List L)
{
    return P->Next;
}
Position previous(Position P, List L)
{
    Position Q = L;
    while (Q->Next != P)
    {
        Q = Q->Next;
    }
    return Q;
}
void insertList(ElementType x, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(Node));
    T->Elements = x;
    T->Next = P->Next;
    P->Next = T;
}
void deleteList(Position P, List *pL)
{
    Position T;
    if (P->Next != NULL)
    {
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}
Position locate(ElementType x, List L)
{
    Position P = first(L);
    Position E = endList(L);
    while (P != E)
    {
        if (P->Next->Elements == x)
        {
            return P;
        }
        else
        {
            P = P->Next;
        }
    }
}
void append(ElementType x, List *pL)
{
    Position P = (*pL);
    while (P->Next != NULL)
    {
        P = P->Next;
    }
    Position temp;
    temp = (Position)malloc(sizeof(Node));
    temp->Elements = x;
    temp->Next = NULL;
    P->Next = temp;
}
void printOddNumbers(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Elements % 2 != 0)
            printf("%d ", P->Next->Elements);
        P = P->Next;
    }
}
int member(ElementType x, List L)
{
    Position P = L;
    int found = 0;
    while (P->Next != NULL && found == 0)
    {
        if (P->Next->Elements == x)
            found = 1;
        else
            P = P->Next;
    }
    return found;
}
List difference(List L1, List L2)
{
    List L3;
    makenullList(&L3);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Elements, L2))
            append(P->Next->Elements, &L3);
        P = P->Next;
    }
    return L3;
}
//============MAIN=================
int main(int argc, char const *argv[])
{
    List L1, L2, L;
    int i;

    Position p;
    makenullList(&L1);
    makenullList(&L2);
    for (i = 1; i <= 3; i++)
        append(i, &L1);
    for (i = -1; i <= 2; i++)
        append(i, &L2);
    L = difference(L1, L2);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Elements);
        p = p->Next;
    }
    return 0;
}
