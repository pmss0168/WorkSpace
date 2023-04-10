#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;
void makenullList(List *pL){
    (*pL) = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}
int emptyList(List L){
    return (L->Next == NULL);
}
void InsertList(ElementType X,Position P, List *pL){
    Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}
void deleteList(Position P, List *pL){
    Position Temp;
    if (P->Next != NULL){
        Temp =  P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}
Position locate(ElementType x, List L){
    Position P;
    int Found = 0;
    while ((P->Next != NULL) && (Found == 0)){
        if (P->Next->Element == x) Found = 1;
        else
            P = P->Next;
    }
    return P;
}
ElementType retrieve(Position P, List L){
    if (P->Next != NULL)
        return P->Next->Element;
    return NULL;
}
Position first( List L){
    return L;
}
Position endList(List L){
    Position P = L;
    while (P->Next != NULL){
        P = P->Next;
    }
    return P;
}
Position next(Position P, List L){
    return P->Next;
}
void insertList(ElementType X, Position P, List *pL){
    Position T;
    T = (Position)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}
void swap(Position P, Position Q, List *pL){
    ElementType temp;
    temp = P->Next->Element;
    P->Next->Element = Q->Next->Element;
    Q->Next->Element = temp;
}
void sort(List *pL){
    Position P =(*pL);
    while (P->Next != NULL){
        Position Q = next(P,*pL);
        while (Q->Next != NULL){
            if(retrieve(P,*pL) > retrieve(Q,*pL))
                swap(P,Q,pL);
            Q = Q->Next;
        }
        P = P->Next;
    }
    
}
int member(ElementType x, List L){
    Position P = L;
    int Found = 0;
    while ((P->Next != NULL) && (Found == 0)){
        if (P->Next->Element == x){
            Found = 1;
            return 1;
        } 
        else
            P = P->Next;
    }
    return 0;
}

void append(ElementType x, List *pL){
    Position T, P =(*pL);
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}
List unionSet(List L1, List L2){
    List Lkq;
    makenullList(&Lkq);
    Position P,Q;
    P = L1;
    while(P->Next != NULL){
        append(P->Next->Element,&Lkq);
        P = P->Next;
    }
    Q = L2;
    while(Q->Next != NULL){
        if(!member(Q->Next->Element,Lkq))
            append(Q->Next->Element,&Lkq);
        else
            Q = Q->Next;
    }
    sort(&Lkq);
    return Lkq;
}
void removeAll(ElementType x, List *pL){
    Position P = locate(x,*pL);
    while(P->Next != NULL){
        deleteList(P,pL);
        P = locate(x,*pL);
    }
}
void erase(ElementType x, List *pL){
    Position P = locate(x,*pL);
    if(P->Next != NULL)
        deleteList(P,pL);
    else
        printf("Not found %d\n", x);
}
void copyEvenNumbers(List L1, List *pL2){
    makenullList(pL2);
    Position P = L1;
    while((P->Next != NULL)){
        if (P->Next->Element % 2 ==0 ){
            append(P->Next->Element,pL2);
        }
        P = P->Next;
    }
}
int main(){
	
    List L1, L2;
    Position p;
            
    makenullList(&L1);

    append(20, &L1);
    append(21, &L1);
    append(-5, &L1);
    append(10, &L1);
    append(-50, &L1);
        
        
    copyEvenNumbers(L1, &L2);
        
    p=L2;
    while(p->Next!=NULL)
    {		
            printf("%d ",p->Next->Element);
            p=p->Next;
    }
    return 0;
}