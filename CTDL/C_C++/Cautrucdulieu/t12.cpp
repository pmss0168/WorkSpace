#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType element;
	NodeType	next;
};

typedef NodeType Position;
typedef Position List;

typedef List Stack; 

void MakeNullList(List *Header) {
	(*Header)=(NodeType)malloc(sizeof(struct Node));
	(*Header)->next= NULL;
}

int EmptyList(List L) { 
	return (L->next==NULL);
}

void InsertList(ElementType X,Position P, List *L) {	
	Position T;
	T=(NodeType)malloc(sizeof(struct Node));
	T->element=X;
	T->next=P->next;
	P->next=T;
}

void DeleteList(Position P, List *L) { 
	Position Temp;
	if (P->next!=NULL) {  
		Temp=P->next; 
		P->next=Temp->next; 
		free(Temp);
	}
}

Position Locate(ElementType X, List L) {	
	Position P;
	int Found = 0;
	P = L;
	while ((P->next != NULL) && (Found == 0))
		if (P->next->element == X) Found = 1;
		else P = P->next;
	return P;
} 
 
ElementType Retrieve(Position P, List L) {
	if (P->next!=NULL)
		return P->next->element;
} 

Position First(List L) {	
	return L; 
} 

Position EndList(List L) {
	Position P;
	P=First(L);
	while (P->next!=NULL) 
		P=P->next;
	return P;
}
 
Position Next(Position P, List L) {	
	return P->next;
}

void MakeNullStack(Stack *S) { 
	MakeNullList(S);
}

int EmptyStack(Stack S) { 
	return EmptyList(S);
}

void Push(ElementType X, Stack *S) { 
	InsertList(X, First(*S), S);
}

void Pop(Stack *S) {
	DeleteList(First(*S), S);
}

ElementType Top(Stack S) {
	return Retrieve(First(S), S);
}

void ReadStack(Stack *S) {	
	int i,N;
	ElementType X;
	MakeNullStack(S);
	printf("So phan tu cua stack N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		Push(X, S);
	}
}

void PrintStack(Stack S) {
	while (!EmptyStack(S)) {
		printf("%d ",Top(S));
		Pop(&S);
	}
	printf("\n");
}


main() {
	Stack S;
	ReadStack(&S);
	printf("Stack vua nhap: ");
	PrintStack(S); 
	return 0;
} 

 

  
