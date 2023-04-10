#include<stdio.h>
#define Maxlength 50
typedef int Position;
typedef int ElementType;
typedef struct{
	Position Last;
	ElementType Elements[Maxlength];
}List;
void makenullList(List *L){
	L->Last=0;
}
void insertSet(ElementType x,List *L){
	if(L->Last == Maxlength)
	 printf("danh sach day");
	else{
		L->Elements[L->Last] = x;
		L->Last++;
	}
}
int member(ElementType x,List L){
	int f=0;
	Position P=1;
	while (P!=L.Last+1 && !f)
		if(L.Elements[P-1]==x)
		 f=1;
		else P++;
	return f;
}
void readList(List *L){
	Position P=1;
	makenullList(L);
	ElementType x;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(!member(x,*L))
		 insertSet(x,L);
	}
}
void hop(List L1,List L2,List *L){
	Position P=1;
	makenullList(L);
	ElementType x;
	while(P!=L1.Last+1){
		insertSet(L1.Elements[P-1],L);
		P++;
	}
    P = 1;
	while(P != L2.Last + 1){
		if(!member(L2.Elements[P-1],*L)){
		    insertSet(L2.Elements[P-1],L);
	    }
	    P++;
	}
}
void printList(List L){
	Position P=1;
	while(P!=L.Last+1){
		printf("%d ",L.Elements[P-1]);
		P++;
		
	}
	printf("\n");
}
int main (){
	List L1,L2,L3;
	readList(&L1);
	readList(&L2);
	printList(L1);
	printList(L2);
	hop(L1,L2,&L3);
	printList(L3);
	return 0;
}