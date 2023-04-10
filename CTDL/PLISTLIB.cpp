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
void insertList(ElementType X,Position P, List *pL){
    Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}
void deleteList(Position P, List *pL){
    Position Temp;
    if (P->Next != NULL){
    	Temp = (struct Node*)malloc(sizeof(struct Node*))
        Temp =  P->Next;
        P->Next = P->Next->Next;
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