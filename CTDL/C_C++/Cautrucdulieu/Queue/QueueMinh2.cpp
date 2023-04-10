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
        return 0;
    }
    return Q.Elements[Q.Front];
}
void ndeQueue(Queue *pQ, int n)
{
    int tp = pQ->Elements[pQ->Front];
    if (!emptyQueue(*pQ))
    {
        pQ->Front = pQ->Front + 1;
        if (pQ->Front > pQ->Rear)
        {
            makenullQueue(pQ);
            printf("%d 0\n", tp);
        }
        else if (pQ->Front <= pQ->Rear)
        {
            printf("%d %d\n", tp, n);
        }
    }
    else
    {
        printf("%d 0\n", n);
    }
}
int main()
{
    Queue Q;
    makenullQueue(&Q);
    int n, x, count = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++)
    {
        scanf("%c", &c);
        if (c == 'E')
        {
            scanf("%d", &x);
            enQueue(x, &Q);
            if (count == -1)
            {
                count = 1;
            }
            else
            {
                count = count + 1;
            }
            printf("%d\n", count);
        }
        else if (c == 'D')
        {
            if (count > 0)
            {
                count = count - 1;
            }
            else
            {
                count = -1;
            }
            ndeQueue(&Q, count);
        }
    }
    return 0;
}