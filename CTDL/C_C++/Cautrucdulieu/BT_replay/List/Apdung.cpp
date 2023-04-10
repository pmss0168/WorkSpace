#include <stdio.h>
#include <stdlib.h>
#include "AListLib.cpp"
void readList(List *pL)
{
    makenullList(pL);
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        ElementType x;
        scanf("%d", &x);
        insertList(x, pL->Last + 1, pL);
    }
}
void printfList(List L)
{
    Position P = 1;
    while (P != endList(L))
    {
        printf("%d ", retrieve(P, L));
        P++;
    }
    printf("\n");
}
Position findXone(ElementType x, List L)
{
    Position P = first(L);
    while (P != endList(L))
    {
        if (retrieve(P, L) == x)
        {
            return P;
        }
        P++;
    }
    return endList(L);
}
void deleteFirst(ElementType x, List *pL)
{
    Position P = findXone(x, *pL);
    deleteList(P, pL);
}
//======================
int evenNumbers(List L1, List *pL2)
{
    Position P = 1, Q = 0;
    int temp = 0;
    makenullList(pL2);
    while (P != L1.Last + 1)
    {
        if (L1.Elements[P - 1] % 2 == 0)
        {
            Q++;
            temp++;
            insertList(L1.Elements[P - 1], Q, pL2);
        }
        P++;
    }
    return temp;
}
float sumList(List L)
{
    Position P = 1;
    float sum = 0;
    while (P != endList(L))
    {
        sum += retrieve(P, L);
        P++;
    }
    return sum;
}
//=======================
ElementType minList(List L)
{
    ElementType min = retrieve(first(L), L);
    Position P = first(L) + 1;
    while (P != endList(L))
    {
        if (min > retrieve(P, L))
        {
            min = retrieve(P, L);
        }
        P++;
    }
    return min;
}
int main(int argc, char const *argv[])
{
    List L, L1;
    makenullList(&L);
    makenullList(&L1);
    readList(&L);
    printfList(L);
    float temp = evenNumbers(L, &L1);
    temp = sumList(L1) / temp;
    printfList(L1);
    printf("%.3f", temp);
    return 0;
}
