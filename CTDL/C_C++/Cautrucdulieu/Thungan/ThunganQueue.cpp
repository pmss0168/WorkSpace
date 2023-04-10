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
void xep_hang(int sokhach, int tgden_tb, Queue *pQ)
{
    int stt_khach;
    makenullQueue(pQ);
    for (stt_khach = 1; stt_khach <= sokhach; stt_khach++)
        enQueue(stt_khach * tgden_tb, pQ);
}
int tinhsoquayOpen(int sokhach, int soquayMax, int timeXuly, int timeden_tb, int tg_mt, float *timeTb)
{
    Queue Q;

    int sumTime, thoidiemDi, thoidiemDen, soquayOpen;

    int thoidiemKhachtruocdi[soquayMax];

    int stt_quay;

    *timeTb = tg_mt + 1;

    soquayOpen = 1;

    while (soquayOpen <= soquayMax && *timeTb > tg_mt)
    {
        for (stt_quay = 1; stt_quay <= soquayOpen; stt_quay++)
        {
            thoidiemKhachtruocdi[stt_quay - 1] = 0;
        }

        xep_hang(sokhach, timeden_tb, &Q);

        sumTime = 0;

        while (!emptyQueue(Q))
        {
            for (stt_quay = 1; stt_quay <= soquayOpen && !emptyQueue(Q); stt_quay++)
            {
                thoidiemDen = front(Q);

                deQueue(&Q);

                if (thoidiemDen >= thoidiemKhachtruocdi[stt_quay - 1])
                {
                    thoidiemDi = thoidiemDen + timeXuly;
                }
                else
                {
                    thoidiemDi = thoidiemKhachtruocdi[stt_quay - 1] + timeXuly;
                }
                thoidiemKhachtruocdi[stt_quay - 1] = thoidiemDi;

                sumTime = sumTime + (thoidiemDi - thoidiemDen);
            }
        }
        *timeTb = sumTime / sokhach;
        if (*timeTb > tg_mt)
        {
            printf("Mo %d quay: ", (soquayOpen));
            printf("Thoi gian TB ma Khach phai bo ra: %0.1f giay\n", *timeTb);
        }
        soquayOpen++;
    }

    return soquayOpen - 1;
}
int main(int argc, char const *argv[])
{
    int sokhach, soquayMax, timeXuly, timeDen, time_mt;
    float time_TB;
    printf("moi nhap: \n");
    scanf("%d", &sokhach);
    scanf("%d", &soquayMax);
    scanf("%d", &timeXuly);
    scanf("%d", &timeDen);
    scanf("%d", &time_mt);
    int soquayOpen = tinhsoquayOpen(sokhach, soquayMax, timeXuly, timeDen, time_mt, &time_TB);
    if (time_TB <= time_mt)
    {
        printf("Mo %d quay: ", (soquayOpen));
        printf("Thoi gian TB ma Khach phai bo ra: %0.1f giay", time_TB);
        printf("\n=> Sieu thi se mo %d quay\n", soquayOpen);
    }
    else
    {
        printf("\nVoi %d quay hien co, khach phai bo ra TB %0.1f giay moi hoan thanh viec thanh toan!!!.\n", soquayOpen, time_TB);
    }

    return 0;
}
