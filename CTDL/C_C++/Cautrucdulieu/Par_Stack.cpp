#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50
typedef char ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;

void makenullStack(Stack *pS)
{
    pS->Top_idx = MaxLength;
}
int emptyStack(Stack S)
{
    return S.Top_idx == MaxLength;
}
int full(Stack S)
{
    return S.Top_idx == 0;
}
ElementType top(Stack S)
{
    if (!emptyStack(S))
        return S.Elements[S.Top_idx];
    else
        printf("Error!! Empty Stack!!");
    return 0;
}
void pop(Stack *pS)
{
    if (!emptyStack(*pS))
    {
        pS->Top_idx += 1;
    }
    else
        printf("Error!! Empty Stack!!");
}
void push(ElementType x, Stack *pS)
{
    if (!full(*pS))
    {
        pS->Top_idx -= 1;
        pS->Elements[pS->Top_idx] = x;
    }
    else
        printf("Error!! Full Stack");
}
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
char chuanhoa(char ch)
{
    if ((ch >= 'A' && ch <= 'Z'))
        return ch + 32;
    return ch;
}
int ktchuoi(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
int main(int argc, char const *argv[])
{
    char s[255];
    Stack ngc;
    makenullStack(&ngc);
    Queue xuoi;
    makenullQueue(&xuoi);
    fgets(s, 255, stdin);
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
    int i;
    for (i = 0; i < strlen(s); ++i)
    {
        if (ktchuoi(s[i]))
        {
            char temp = chuanhoa(s[i]);
            push(temp, &ngc);
            enQueue(temp, &xuoi);
        }
    }
    while (!emptyQueue(xuoi))
    {
        if (top(ngc) != front(xuoi))
        {
            printf("\"%s\" doc xuoi khac doc nguoc", s);

            break;
        }
        else
        {
            deQueue(&xuoi);
            pop(&ngc);
        }
    }

    if (emptyQueue(xuoi))
        printf("\"%s\" doc xuoi va doc nguoc nhu nhau", s);
    return 0;
}
