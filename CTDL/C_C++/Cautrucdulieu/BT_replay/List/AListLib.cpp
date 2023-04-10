#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100
typedef int Position;
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;
void makenullList(List *pL)
{
    pL->Last = 0;
}
int emptyList(List L)
{
    return L.Last == 0;
}
int fullList(List L)
{
    return L.Last == MaxLength;
}
Position first(List L)
{
    return 1;
}
Position endList(List L)
{
    return L.Last + 1;
}
ElementType retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}
Position next(Position P, List L)
{
    return P + 1;
}
Position prevous(Position P, List L)
{
    return P - 1;
}
Position locate(ElementType x, List L)
{
    Position P = first(L);
    while (P != endList(L))
    {
        if (retrieve(P, L) == x)
            return P;
        P = next(P, L);
    }
    return L.Last + 1;
}
void insertList(ElementType x, Position P, List *pL)
{
    if (fullList(*pL))
        printf("Danh sach day!!!");
    else
    {
        if (P < 1 || P > endList(*pL))
            printf("Vi tri khong ton tai!!!");
        else
        {
            Position Q;
            for (Q = pL->Last; Q > P; --Q)
            {
                pL->Elements[Q] = pL->Elements[Q - 1];
            }
            pL->Elements[P - 1] = x;
            pL->Last++;
        }
    }
}
void deleteList(Position P, List *pL)
{
    if (P < 1 || P > endList(*pL))
        printf("Vi tri khong ton tai!!!");
    else
    {
        if (emptyList(*pL))
            printf("Danh sach rong!!!");
        else
        {
            Position Q;
            for (Q = P; Q < endList(*pL); ++Q)
            {
                pL->Elements[Q - 1] = pL->Elements[Q];
            }
            pL->Last--;
        }
    }
}
//===========Bo sung phuong thuc moi =========================
int member(ElementType x, List L)
{
    Position P = 1;
    while (P != L.Last + 1)
    {
        if (L.Elements[P - 1] == x)
            return 1;
        P++;
    }
    return 0;
}
void insertSet(ElementType x, List *pL)
{
    if (pL->Last == MaxLength)
        printf("Danh sach day!!!");
    else
    {
        pL->Elements[pL->Last++] = x;
    }
}
//=======================Else====================================
void normalize(List *pL)
{
    Position P = 1;
    while (P != pL->Last + 1)
    {
        Position Q = P + 1;
        while (Q != pL->Last + 1)
        {
            if (pL->Elements[P - 1] == pL->Elements[Q - 1])
                deleteList(Q, pL);
            else
                Q++;
        }
        P++;
    }
}
void copyEvenNumbers(List L1, List *pL2)
{
    Position P = 1, Q = 0;
    makenullList(pL2);
    while (P != L1.Last + 1)
    {
        if (L1.Elements[P - 1] % 2 == 0)
        {
            Q++;
            insertList(L1.Elements[P - 1], Q, pL2);
        }
        P++;
    }
}
void unionSet(List L1, List L2, List *pL)
{
    Position P = 1;
    makenullList(pL);
    *pL = L1;
    while (P != L2.Last + 1)
    {
        if (!member(L2.Elements[P - 1], L1))
            insertSet(L2.Elements[P - 1], pL);
        P++;
    }
}
void intersection(List L1, List L2, List *pL)
{
    Position P = 1;
    makenullList(pL);
    while (P != L1.Last + 1)
    {
        if (member(L1.Elements[P - 1], L2))
            insertSet(L1.Elements[P - 1], pL);
        P++;
    }
}
void printList(List L)
{
    if (L.Last == 0)
        printf("Danh sach rong!!!");
    else
    {
        Position P = 1;
        while (P != L.Last + 1)
        {
            printf("%d ", L.Elements[P - 1]);
            P++;
        }
    }
}
void sort(List *pL)
{
    Position P = 1;
    while (P != pL->Last)
    {
        Position Q = P + 1;
        while (Q != pL->Last + 1)
        {
            if (pL->Elements[P - 1] > pL->Elements[Q - 1])
            {
                ElementType x = pL->Elements[P - 1];
                pL->Elements[P - 1] = pL->Elements[Q - 1];
                pL->Elements[Q - 1] = x;
            }
            Q++;
        }
        P++;
    }
}
//============Dinh nghia nhap=================