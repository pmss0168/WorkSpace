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
void deleteList(Position P, List *pL){
    Position T;
    if (P->Next != NULL){
        T = (struct Node*)malloc(sizeof(struct Node*));
        T =  P->Next;
        P->Next = P->Next->Next;	//P->Next = T->Next;
        free(T);
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
Position endList(List L){
    Position P = L;
    while (P->Next != NULL){
        P = P->Next;
    }
    return P;
}
int member(ElementType x, List L){
    Position P = L;
    while ((P->Next != NULL)){
        if (P->Next->Element == x){
            return 1;
        } 
        else
            P = P->Next;
    }
    return 0;
}
void append(ElementType x, List *pL){
    Position p = (struct Node*)malloc(sizeof(struct Node*));
    p->Element = x;
    p->Next = NULL;
    if(*pL == NULL){
        *pL = p;
    }
    else{
        Position q = *pL;
        while(q->Next != NULL){
            q = q->Next;
        }
        q->Next = p;
    }
}
void insertList(ElementType X, Position P, List *pL){
    Position T;
    T = (Position)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}
void readList(List *pL){
    int n,i;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d ", &x);
        insertList(x,endList(*pL),pL);
        }
    }

void printList(List L){
    Position p;
    p = L;
    while(p->Next != NULL){
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    printf("\n");
}
void removeAll(ElementType x, List *pL){
    Position P = locate(x,*pL);
    while(P->Next != NULL){
        deleteList(P,pL);
        P = locate(x,*pL);
    }
}


int main(){
    List L;
    ElementType d;
    readList(&L);
    scanf("%d ",&d);
    printList(L);
    removeAll(d,&L);
    printList(L);
}