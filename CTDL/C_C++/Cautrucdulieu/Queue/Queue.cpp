#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100

typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void makenullQueue(Queue *pQ)
{
    pQ->Front = -1;
    pQ->Rear = -1;
}
int emptyQueue(Queue Q)
{
    return Q.Front == -1;
} // vi front la dau hang nen chi can check dau hang;
int fullQueue(Queue Q)
{
    return (Q.Rear - Q.Front + 1) == MaxLength;
}
void enQueue(ElementType x, Queue *pQ)
{
    if (!fullQueue(*pQ))
    {
        if (emptyQueue(*pQ))
            pQ->Front = 0;
        if (pQ->Rear == MaxLength - 1)
        {
            int i;
            for (i = pQ->Front; i <= pQ->Rear; i++)
            {
                pQ->Elements[i - pQ->Front] = pQ->Elements[i];
            }
            pQ->Rear = MaxLength - 1 - pQ->Front;
            pQ->Front = 0;
        }
        // bi tran;
        pQ->Rear = pQ->Rear + 1;
        pQ->Elements[pQ->Rear] = x;
    }
    else
        printf("Loi!! Hang day!");
}
void deQueue(Queue *pQ)
{
    if (emptyQueue(*pQ))
    {
        printf("Empty Queue!!!");
    }
    else
    {
        pQ->Front++;
        if (pQ->Front > pQ->Rear)
            makenullQueue(pQ);
    }
}
ElementType front(Queue Q)
{
    if (emptyQueue(Q))
    {
        printf("Empty Queue!!!");
        // return ;
    }

    else
        return Q.Elements[Q.Front];
}
int main(int argc, char const *argv[])
{
    int n, i;
    int kq = 0;
    Queue cv;
    makenullQueue(&cv);
    scanf("%d", &n);
    int a[n];
    int x;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enQueue(x, &cv);
    }
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    i = 0;
    while (!emptyQueue(cv))
    {
        if (a[i] == front(cv))
        {
            deQueue(&cv);
            i++;
        }
        else
        {
            enQueue(front(cv), &cv);
            deQueue(&cv);
        }
        kq++;
    }

    printf("%d", kq);
    return 0;
}
