#include <stdio.h>
#include <conio.h>

#define Maxlength 100

/*========================Khai báo danh sách đặc========================*/

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Elements[Maxlength];
    Position Last;
} List;

/*========================Kết thúc khai báo=============================*/

/*  List null */

void makenullList(List *L){
    L->Last = 0;
}

/* Check Null */

int emptyList(List L){
    return (L.Last == 0);
}

/* Check Full */

int fullList(List L){
    return (L.Last == Maxlength);
}

/* Return First List */

Position firstList(List L){
    return 1;
}

/* Return End List */

Position endList(List L){
    return L.Last+1;
}

/* Return particle p+1 */

Position next(Position P, List L){
    return P+1;
}

/* Return particle p-1 */

Position previous(Position P, List L){
    return P-1;
}

/* Return value */

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

/* Insert List */

void InsertList(ElementType X, Position P, List *L){
    Position i=0;
    if (fullList(*L))
        printf("\n Danh sach day !!!");
    else 
        if ((P<1)||(P>L->Last+1))
            printf("\n Vi tri khong hop le !!!");
        else {
                for (i=L->Last; i>=P; --i)
                    L->Elements[i]=L->Elements[i-1];
                L->Last++;
                L->Elements[P-1]= X;
        }
}

/* Delete List */

void deleteList(Position P, List *L){
    if ((P>L->Last)||(P<1))
        printf("\n Vi tri khong hop le !!!");
    else 
        if (emptyList(*L))
            printf("\n Danh sach rong");
        else{
            Position i;
            for (i=P; i<L->Last; ++i)
                L->Elements[i-1] = L->Elements[i];
            L->Last--;
        }
}

/* Print List */

void   printList(List L){
    Position P;
    P = firstList(L);
    printf("\n Bat dau in danh sach ");
    while (P!=endList(L)){
        printf("\n%d",retrieve(P,L));
        P = next(P,L);
    }
    printf("\n Ket thuc in danh sach \n");
}

/* Input List */

void readList(List *L){
    int i,N;
    ElementType X;
    makenullList(L);
    printf("\n Nhap vao so phan tu trong danh sach ");
    scanf("%d",&N);
    for (i=1; i<=N; ++i){
        printf("\n Phan tu thu %d la: ",i);
        scanf("%d",&X); fflush(stdin);
        insertList(X,endList(*L),L);
    }
}


Position locate(ElementType X, List L){
    Position P;
    int found = 0;
    P = firstList(L);
    while ((P!=endList(L))&&(found==0)){
        if(retrieve(P,L)==X)
            found=1;
        else P = next(P, L);
    }
    return P;
}

void removeAll(ElementType x, List *pL){
    Position P = locate(x,*pL);
    while(!((P>pL->Last)||(P<1))){
        deleteList(P,pL);
        P = locate(x,*pL);
    }
}
void printOddNumbers(List L){
    Position P = firstList(L);
    while(P != endList(L)){
        if (retrieve(P,L) % 2 != 0)
            printf("%d ", retrieve(P,L));
        P = next(P,L);
    }
}
void erase(ElementType x, List *pL){
    Position P = locate(x,*pL);
    deleteList(P,pL);
}
void copyEvenNumbers(List L1, List *pL2){
    makenullList(pL2);
    Position P = 1;
    while((P != L1.Last + 1)){
        if (L1.Elements[P-1] % 2 == 0){
            insertList(L1.Elements[P-1],pL2->Last + 1, pL2);
        }
        P++;
    }
}
int member(ElementType X, List L){
    Position P;
    int found = 0;
    P = firstList(L);
    while ((P!=endList(L))&&(found==0)){
        if(retrieve(P,L)==X)
            found=1;
        else P = next(P, L);
    }
    return found;
}
void insertSet(ElementType x, List *pL){
    Position i=0;
    if (fullList(*pL))
        printf("\n Danh sach day !!!");
    else{
                pL->Last++;
                pL->Elements[pL->Last - 1]= x;
        }
}
void intersection(List L1, List L2, List *pL){
    makenullList(pL);
    Position P = 1;
    while(P != L1.Last + 1){
        if(member(L1.Elements[P-1],L2)){
            insertSet(L1.Elements[P-1], pL);
        }
        P++;
    }
}