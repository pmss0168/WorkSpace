#include <stdio.h>
#define Maxlength 50

typedef int ElementType;

typedef int Position;

typedef struct {

  ElementType Elements[Maxlength];

  Position    Last;

}List;
//===================
void makenullList(List *L){
    L->Last = 0;
}
int emptyList(List L){
    return L.Last == 0;
}

Position first(List L){
    return 1;
}

Position endList(List L){
    return L.Last + 1;
}

Position next(Position P, List L){
    return P + 1;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

void insertList(ElementType X, Position P, List *L){
    if (L->Last == P)
        printf("\nFull List");
    else
        if ((P < 1)&&(P > L->Last + 1))
            printf("\nLocation Error");
        else{
            Position Q;
            for(Q = L->Last; Q >= P; Q--)
                L->Elements[Q]=L->Elements[Q-1];
            L->Elements[P-1] = X;
            L->Last++;
        }
    
}

void deleteList(Position P, List *L){
    if ((P < 1)&&(P > L->Last))
            printf("\nLocation Error");
    else
        if(emptyList(*L))
        printf("\n Empty List");
        else{
            Position Q;
            for (Q = P; Q < L->Last; ++Q)
                L->Elements[Q-1] = L->Elements[Q];
            L->Last--;
        }
}

void readList(int n,List *L){
    int i;
    ElementType x;
    makenullList(L);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        insertList(x,L->Last + 1,L);
    }
}

void printList(List L){
    Position P = 1;
    while (P != endList(L)){
        printf("%d ",retrieve(P,L));
        P++;
    }
    printf("\n");
}

Position locate(ElementType X,List L){
    Position P = 1;
    while (P != endList(L)){
        if(X == retrieve(P,L))
            return P;
        else
            P++;
    }
    return P;
}
// int sumList(List L){
//     int sum = 0;
//     if(L.Last == 0)
//         return 0;
//     else{
//         Position P = 1;
//         while(P != endList(L)){
//             sum = sum + retrieve(P,L);
//             P++;
//         }
//     }
//     return sum;
// }
// ElementType maxList(List L){
//     Position P = 2;
//     ElementType max = L.Elements[0];
//     while (P != endList(L)){
//         if (max < retrieve(P,L)) max = retrieve(P,L);
//         P++;
//     }
//     return max;
// }
void findAndDelete(ElementType x, List *L){
    while (!(locate(x,*L) == endList(*L))){
            deleteList(locate(x,*L),L);
        }
}
void evenAndOdd(List L){
    List even,odd;
    makenullList(&even);
    makenullList(&odd);
    Position P = 1;
    while(P != endList(L)){
        if (retrieve(P,L) % 2 == 0){
            insertList(retrieve(P,L),endList(even), &even);
        }
        else{
            insertList(retrieve(P,L),endList(odd), &odd);
        }
        P++;
    }
    printList(odd);
    printList(even);
}
int main(){
    List L;
    makenullList(&L);
    int n,k;
    scanf("%d", &n);
    readList(n, &L);
    printList(L);
    evenAndOdd(L);
    return 0;
}