#include <stdio.h>
#include <conio.h>

#define Maxlength 30

/*========================Khai báo danh sách đặc========================*/

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Elements[Maxlength];
    Position Last;
} List;

/*========================Kết thúc khai báo=============================*/

/*  List null */

void MakeNull_List(List *L){
    L->Last = 0;
}

/* Check Null */

int Empty_List(List L){
    return (L.Last == 0);
}

/* Check Full */

int Full_List(List L){
    return (L.Last == Maxlength);
}

/* Return First List */

Position FirstList(List L){
    return 1;
}

/* Return End List */

Position EndList(List L){
    return L.Last+1;
}

/* Return particle p+1 */

Position Next(Position P, List L){
    return P+1;
}

/* Return particle p-1 */

Position Previous(Position P, List L){
    return P-1;
}

/* Return value */

ElementType Retrieve(Position P, List L){
    return L.Elements[P-1];
}

/* Insert List */

void Insert_List(ElementType X, Position P, List *L){
    int i=0;
    if (Full_List(*L))
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

void Delete_List(Position P, List *L){
    if ((P>L->Last)||(P<1))
        printf("\n Vi tri khong hop le !!!");
    else 
        if (Empty_List(*L))
            printf("\n Danh sach rong");
        else{
            Position i;
            for (i=P; i<L->Last; ++i)
                L->Elements[i-1] = L->Elements[i];
            L->Last--;
        }
}

/* Print List */

void   Print_List(List L){
    Position P;
    P = FirstList(L);
    printf("\n Bat dau in danh sach ");
    while (P!=EndList(L)){
        printf("\n%d",Retrieve(P,L));
        P = Next(P,L);
    }
    printf("\n Ket thuc in danh sach \n");
}

/* Input List */

void Read_List(List *L){
    int i,N;
    ElementType X;
    MakeNull_List(L);
    printf("\n Nhap vao so phan tu trong danh sach ");
    scanf("%d",&N);
    for (i=1; i<=N; ++i){
        printf("\n Phan tu thu %d la: ",i);
        scanf("%d",&X); fflush(stdin);
        Insert_List(X,EndList(*L),L);
    }
}

/* Search */

Position Locate(ElementType X, List L){
    Position P;
    int found = 0;
    P = FirstList(L);
    while ((P!=EndList(L))&&(found==0)){
        if(Retrieve(P,L)==X)
            found=1;
        else P = Next(P, L);
    }
    return P;
}
/*choose sort*/
void Swap(Position a, Position b, List *L){
	ElementType t;
	t = L->Elements[a];
	L->Elements[a] = L->Elements[b];
	L->Elements[b] = t;
}

void Sort_List(List *L){
	Position P=FirstList(*L);
	while (P!=EndList(*L)){
		Position Q=Next(P,*L);
		while (Q!=EndList(*L)){
		if ((Retrieve(P,*L)) > (Retrieve(Q,*L)))
		  Swap(P,Q,L);
		Q=Next(Q,*L);
		} // dong ngoac cho nay ne Q tang het roi moi tiep tuc tang P
		P=Next(P,*L);
	}
}
/* Quick sort */
Position partition (List *L, Position low, Position high){
    ElementType pivot = L->Elements[high];
    Position left = low;
    Position right = high - 1;
    while (true){
        while (left <= right && L->Elements[left] < pivot) left++;
        while (right >= left && L->Elements[right] > pivot) right--;
        if (left >= right)  break;
        Swap(left,right,L);
        left++;
        right--;
    }
    Swap(left,right,L);
    return left;
}  
/* Hàm thực hiện giải thuật quick sort */
void quickSort(List *L, Position low, Position high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        Position pi = partition(L, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(L, low, pi - 1);
        quickSort(L, pi + 1, high);
    }
}
// main tam
int main (){
	List L;
	Position P;
	MakeNull_List(&L);
	Read_List(&L);
	printf ("danh sach vua nhap la ");
	Print_List(L);
	quickSort(&L,FirstList(L)-1,EndList(L)-2);
	printf ("\ndanh sach vua sap xep la: ");
	Print_List(L);
	
}
