#include<stdio.h>
#include<conio.h>
//#include"AListLib.c"

#define Maxlength 30
//---------Khai Bao Danh Sach Dac------------
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType	Elements[Maxlength];
	Position	Last;
}List;
//------------Cai Dat Ham--------------------
void makenullList(List *pL){
	pL->Last = 0;
}
void insertList(ElementType X, Position P, List *L){
	int i = 0;
	if(L->Last == Maxlength)
		printf("\nDanh sach day!!!");
	else 
		if(P<1 || P>Maxlength)
			printf("\nVi tri khong hop le!!!");
		else
			for(i = L->Last; i>=P; i--){
				L->Elements[i] = L->Elements[i-1];
			}
	L->Last++;
	L->Elements[P-1]=X;
}
int locate(ElementType x, List L){
	for(int i = 1; i < L.Last+1; i++){
		if(L.Elements[i-1] == x)
			return i;
	}
	return L.Last+1;
}
void deleteList(Position P, List *L){
	int i =0;
	if(P < 1 || (P > L->Last+1))
		printf("\nVi tri khong hop le!!!");
	else
		if(L->Last == 0)
			printf("\nDanh sach rong");
		else{
			for(i=P; i<=L->Last; i++)
				L->Elements[i-1]=L->Elements[i];
			L->Last--;
		}
}	
void erase(ElementType x, List *pL){
	Position p;
	p = locate(x,*pL);
	if(p > 1 || p < pL->Last+1){
		deleteList(p,pL);
	}
}
void normalize(List *pL){
	int p = 1;
	while(p != pL->Last+1){
		int q = p + 1;
		while(q != pL->Last+1){
			if(pL->Elements[p-1] == pL->Elements[q-1])
				deleteList(q,pL);
			else
				q +=1;
		}
		p += 1;
	}
}
int member(ElementType x, List L){
	for(int i = 1; i < L.Last+1; i++){
		if(L.Elements[i-1] == x)
			return 1;
	}
	return 0;
}
void insertSet(ElementType x, List *pL){
    pL->Last+=1;
    pL->Elements[pL->Last-1] = x;
    
}
void intersection(List L1, List L2, List *pL){
	makenullList(pL);
	for(int i = 1; i < L1.Last+1; i++){
		if(member(L1.Elements[i-1],L2)==1)
			insertSet(L1.Elements[i-1], pL);
	}
}
void sort(List *pL){
	for(int i = 1; i < pL->Last; i++){
		for(int j = i +1; j < pL->Last+1; j++){
			if(pL->Elements[i-1] > pL->Elements[j-1]){
				int temp = pL->Elements[i-1];
				pL->Elements[i-1] = pL->Elements[j-1];
				pL->Elements[j-1] = temp;
			}
		}
	}
}
void unionSet(List L1, List L2, List *pL){
	makenullList(pL);
	for(int i = 1; i < L1.Last+1; i++){
		insertSet(L1.Elements[i-1],pL);
	}
	for(int i = 1; i < L2.Last+1; i++){
		if(!member(L2.Elements[i-1],*pL))
			insertSet(L2.Elements[i-1],pL);
	}
}
void copyEvenNumbers(List L1, List *pL2){
    makenullList(pL2);
    for(int i = 1; i < L1.Last+1; i++){
        if(L1.Elements[i-1] % 2 == 0){
            insertList(L1.Elements[i-1],pL2->Last+1,pL2);
        }
    }
}
void removeAll(ElementType x, List *pL){
    Position p = locate(x, *pL);
    while(p != pL->Last+1){
        deleteList(p,pL);
        p = locate(x, *pL);
    }
}
float getAvg(List L){
    int s = 0;
    float tbc = 0; 
    if(L.Last == 0)
        return -10000.0000;
    for(int i = 0; i < L.Last; i++){
        s += L.Elements[i];
    }
    tbc = (float) s/L.Last;
    return tbc;
}
void printList(List L){
    for(int i = 1; i < L.Last+1; i++){
        printf("%d ",L.Elements[i-1]);
    }
    printf("\n");
}
void readList(List *pL){
    makenullList(pL);
    ElementType x;
    int i, n;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        insertList(x,pL->Last+1,pL);
    }
}

//-----------Ham Main----------------------

int main(){
    List L;
    readList(&L);
    tbc(L);
    return 0;
}