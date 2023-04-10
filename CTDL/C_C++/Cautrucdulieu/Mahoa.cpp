#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 225
typedef char ElementType;
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
int main(int argc, char const *argv[])
{
    char s[225], temp[225], *kq;
    Queue q;
    makenullQueue(&q);
    kq = (char *)calloc(225, sizeof(char));
    fgets(s, 225, stdin);
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
    fgets(temp, 225, stdin);
    if (temp[strlen(temp) - 1] == '\n')
        temp[strlen(temp) - 1] = '\0';

    int i;
    for (i = 0; i < strlen(temp); ++i)
    {
        enQueue(temp[i], &q);
    }
    for (i = 0; i < strlen(s); ++i)
    {
        kq[strlen(kq)] = s[i] + (front(q) - 48);
        enQueue(front(q), &q);
        deQueue(&q);
    }
    puts(kq);
    return 0;
}
