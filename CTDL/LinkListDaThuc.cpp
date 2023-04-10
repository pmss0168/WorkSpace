#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;

DaThuc khoitao()
{
    DaThuc D;
    D = (struct Node *)malloc(sizeof(struct Node));
    D->Next = NULL;
    return D;
}

void inDaThuc(DaThuc d)
{
    Position i = d;
    printf("%0.3fX^%d ", i->Next->e.he_so, i->Next->e.bac);
    for (i = i->Next; i->Next != NULL; i = i->Next)
    {
        if (i->Next->e.he_so >= 0)
        {
            printf("+ %0.3fX^%d ", i->Next->e.he_so, i->Next->e.bac);
        }
        else
        {
            printf("- %0.3fX^%d ", -i->Next->e.he_so, i->Next->e.bac);
        }
    }
}
DaThuc nhanDaThuc(DaThuc d1, DaThuc d2)
{
    DaThuc New = khoitao();
    Position PD1 = d1;
    Position PD2 = d2;
    DonThuc e, e2;
    for (PD1 = d1; PD1->Next != NULL; PD1 = PD1->Next)
    {
        e = PD1->Next->e;
        for (PD2 = d2; PD2->Next != NULL; PD2 = PD2->Next)
        {
            e2.bac = e.bac + PD2->Next->e.bac;
            e2.he_so = e.he_so * PD2->Next->e.he_so;
            chenDonThuc(e2, &New);
        }
    }
    return New;
}
DaThuc nhanDaThuc(DaThuc d1, DaThuc d2){
    DaThuc kq = khoitao();
    DonThuc e1,e2;
    DaThuc p = d1;
    while(p->Next != NULL){
        e1 = p->Next->e;
        DaThuc q = d2;
        while(q->Next != NULL){
            e2.he_so = e1.he_so * q->Next->e.he_so;
            e2.bac = e1.bac + q->Next->e.bac;
            chenDonThuc(e2, &kq);
            q = q->Next;
        }
        p = p->Next;
    }
    return kq;
}
DaThuc tinhDaoHam(DaThuc D)
{
    DaThuc New = khoitao();
    DonThuc e;
    for (Position p = D; p->Next != NULL; p = p->Next)
    {
        e.bac = p->Next->e.bac - 1;
        e.he_so = p->Next->e.he_so * p->Next->e.bac;
        chenDonThuc(e, &New);
    }
    return New;
}
DaThuc congDaThuc(DaThuc d1, DaThuc d2)
{
    DaThuc D = khoitao();
    for (Position p = d1; p->Next != NULL; p = p->Next)
    {
        chenDonThuc(p->Next->e, &D);
    }
    for (Position p = d2; p->Next != NULL; p = p->Next)
    {
        chenDonThuc(p->Next->e, &D);
    }
    return D;
}
DaThuc nhapDaThuc()
{
    DaThuc D = khoitao();
    int n;
    scanf("%d", &n);
    DonThuc e;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%d", &e.he_so, &e.bac);
        chenDonThuc(e, &D);
    }
    return D;
}

void chenDonThuc(DonThuc s, DaThuc *pD)
{
    Position new, p;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->e = s;
    new->Next = NULL;
    for (p = *pD; p->Next != NULL; p = p->Next)
    {
        if (p->Next->e.bac <= s.bac)
        {
            if (p->Next->e.bac == s.bac)
            {
                p->Next->e.he_so += s.he_so;
                return;
            }
            else
            {
                new->Next = p->Next;
                p->Next = new;
                return;
            }
        }
    }
    new->Next = p->Next;
    p->Next = new;
}