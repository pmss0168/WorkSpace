#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
    (*pL) = (struct Node*)malloc(sizeof(struct Node*));
    (*pL)->Next = NULL;
}
int member(int x, List L){
    Position p = L;
    while(p->Next != NULL){
        if(p->Next->Element == x){
            return 1;
        }
        p = p->Next;
    }
    return 0;
}
void insertSet(ElementType x, List *pL){
    pL->Elements[pL->Last] = x;
    pL->Last++;
}
void append(ElementType x, List *pL){
    Position p;
    p = (struct Node*)malloc(sizeof(struct Node*));
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
void append(int c, List *pd){
	Position P = *pd;
	while(P->Next != NULL){
		P = P->Next;
	}
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = c;
	T->Next = P->Next;
	P->Next = T;
}
//void readList(List *pL){
//    Position p;
//    int n,i;
//    ElementType x;
//    makenullList(pL);
//    p = *pL;
//    scanf("%d", &n);
//    for(i = 1; i <= n; i++){
//        scanf("%d ", &x);
//        if(!member(x, p)){
//            Position t = (struct Node*)malloc(sizeof(struct Node*));
//            t->Element = x;
//            t->Next = p->Next;
//            p->Next = t;
//            p = p->Next;
//        }
//    }
//}
void readList(List *pL){
    Position p;
    int n,i;
    ElementType x;
    (*pL) = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
    p = *pL;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d ", &x);
        Position t = (struct Node*)malloc(sizeof(struct Node*));
        t->Element = x;
        t->Next = p->Next;
        p->Next = t;
        p = p->Next;
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
void deletexList(ElementType x, List *pL){
	Position p = *pL;
	while(p->Next != NULL){
		if(member(x,p)){
			Position t;
			t->Next = p->Next;
			p->	Next = p->Next->Next;
			free(t);
		}
		p = p->Next;
	}
}
List unionSet(List L1, List L2){
    List kq;
    makenullList(&kq);
    while(L1->Next != NULL){
        append(L1->Next->Element, &kq);
        L1 = L1->Next;
        
    }
    while(L2->Next != NULL){
        if(!member(L2->Next->Element, kq))
            append(L2->Next->Element, &kq);
        L2 = L2->Next;
    }
    return kq;
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
void printOddNumbers(List L){
    Position p = L;
    while(p->Next != NULL){
        if(p->Next->Element % 2 != 0)
            printf("%d ",p->Next->Element);
        p = p->Next;
    }
    printf("\n");
}

int main(){
    List L;
    ElementType d;
    readList(&L);
    scanf("%d ",&d);
    printList(L);
    deletexList(d,&L);
    printList(L);
}






















