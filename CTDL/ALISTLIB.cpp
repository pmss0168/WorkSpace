#include<stdio.h>
#include<conio.h>

#define Maxlength 30
//---------Khai Bao Danh Sach Dac------------
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType	Elements[Maxlength];
	Position	Last;
}List;

//---------Cai Dat Thu Vien------------------
//Danh sach rong 
void makenullList(List *L){
	L->Last = 0;
}
//Kiem tra rong
int emptyList(List L){
	return (L.Last==0);
}
//Kiem tra danh sach day
int fullList(List L){
	return(L.Last==Maxlength);
}
//Tra ve vi tri dau danh sach
Position firstList(List L){
	return 1;
}
//Tra ve vi tri sau phan tu cuoi trong danh sach
Position endList(List L){
	return L.Last+1;
}
//Ham tra ve vi tri phan tu ke phan tu P trong danh sach
Position next(Position P, List L){
	return P+1;
}
//Ham tra ve vi tri phan tu truoc phan tu P trong danh sach
Position previous(Position P, List L){
	return P-1;
}
//Ham tra ve noi dung cua phan tu tai vi tri P trong danh sach
ElementType retrieve(Position P, List L){
	return L.Elements[P-1];
}
//Them phan tu co noi dung X vao vi tri P trong danh sach
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
//Xoa phan tu tai vi tri P trong danh sach
void deleteList(Position P, List *L){
	int i =0;
	if(P<1 || (P>L->Last+1))
		printf("\nVi tri khong hop le!!!");
	else{
		if(EmptyList(*L))
			printf("\nDanh sach rong");
		else
			for(i=P; i<=L->Last; i++)
				L->Elements[i-1]=L->Elements[i];
	}
	L->Last--;
}
//In sanh sach ra man hinh 
void printList(List L){
	Position P = FirstList(L);
	printf("\nBat dau in danh sach");
	while(P != EndList(L)){
		printf("%d ",Retrieve(P,L));
		P = Next(P,L);
	}
	printf("\nKet thuc in danh sach");
}
//Nhap danh sach tu ban phim
void readList(List *L){
	int i,n;
	ElementType X;
	MakeNullList(L);
	printf("\nNhap vao so phan tu trong danh sach");
	scanf("\n%d",&n);fflush(stdin);
	for(i=0; i<=n; i++){
		printf("\nPhan tu thu %d la: ",i);
		scanf("%d",&X);fflush(stdin);
		InsertList(X,EndList(*L),L);
	}
}
//Ham tim vi tri dau tien co noi dung X trong danh sach
Position locate(ElementType X, List L){
	Position P;
	int found = 0;
	P = FirstList(L);
	while((P!=EndList(L)) && (found==0)){
		if(Retrieve(P,L) == X)
			found=1;
		else
			P = Next(P,L);
	}
	return P;
}