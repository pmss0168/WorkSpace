#include <stdio.h>
#include <stdlib.h>
#define MaxLength 50
typedef int ElementType;
// ===== mang ========vong=======
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;
//=========Singly Linked========
// struct Node{
//     ElementType Element;
//     struct Node* Next;
// };
// typedef struct Node* Position;
// typedef struct{
//     Position Front, Rear;
// }Queue;
//===== vong ======
// void makenullQueue(Queue *pQ){
//     pQ->Front =-1;
//     pQ->Rear = -1;
// }
// int emptyQueue(Queue Q){
//     return Q.Front == -1;
// }
// int fullQueue(Queue Q){
//     return ((Q.Rear - Q.Front + 1) % MaxLength) == 0;
// }
// void deQueue(Queue *pQ){
//     if (!emptyQueue(*pQ)){
//         if (pQ->Front==pQ->Rear)
//             makenullQueue(pQ);
//         else
//             pQ->Front=(pQ->Front+1)%MaxLength;
//     }
//     else printf("Loi: Hang rong!");
// }
// void enQueue(ElementType x, Queue *pQ){
//     if(fullQueue(*pQ)){
//         printf("Full Queue");
//     }
//     else{
//         if(emptyQueue(*pQ))
//             pQ->Front = 0;
//         else{
//             pQ->Front = 0;
//             pQ->Rear = (pQ->Rear + 1) % MaxLength;
//             pQ->Elements[pQ->Rear] = x;
//         }
//     }
// }
// mang
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

    if (pQ->Front == -1)
    {
        printf("Empty Queue!!!");
    }
    else
    {
        pQ->Front++;
        if (pQ->Front > pQ->Rear)
        {
            pQ->Front = -1;
            pQ->Rear = -1;
        }
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

// void makenullQueue(Queue *pQ){
//     Position Header;
//     Header = (Position)malloc(sizeof(struct Node));
//     Header->Next = NULL;
//     pQ->Front = Header;
//     pQ->Rear = Header;
// }
// int emptyQueue(Queue Q){
//     return (Q.Front == Q.Rear);
// }// O(1);
// ElementType front(Queue Q){
//     if (!emptyQueue(Q)){
//         return Q.Front->Next->Element;
//     }
//     else
//         printf("Empty Queue");
// }
// void enQueue(ElementType x, Queue *pQ){
//     pQ->Rear->Next = (Position)malloc(sizeof(struct Node));
//     pQ->Rear = pQ->Rear->Next;
//     pQ->Rear->Element = x;
//     pQ->Rear->Next == NULL;
// }
// void deQueue(Queue *pQ){
//     if(!emptyQueue(*pQ)){
//         Position temp;
//         temp = pQ->Front;
//         pQ->Front = pQ->Front->Next;
//         free(temp);
//     }
//     else
//         printf("Empty Queue");
// }

int main(int argc, char const *argv[])
{
    int n, i, x;
    int kq = 0;
    Queue cv;
    makenullQueue(&cv);
    printf("Nhap vao n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enQueue(x, &cv);
    }
    printf("Ket thuc nhap!!!\n");
    printf("in Queue\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", front(cv));
        deQueue(&cv);
    }
    return 0;
}
