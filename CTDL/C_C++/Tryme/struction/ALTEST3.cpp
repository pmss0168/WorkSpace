#include <stdio.h>
#include <conio.h>
#include <D:\Wordspace\C_C++\Tryme\struction\ALISTLIB.cpp>

int main(){
    List L;
    ElementType X;
    Position P;
    MakeNull_List(&L);
    printf("\n\nNhap danh sach tu ban phim\n\n");
    Read_List(&L);
    printf("\n\nDanh sach vua nhap la: \n\n");
    Print_List(L);
    printf("\n\nNhap noi dung phan tu can dung\n\n");
    scanf("%d",&X);
    P=Locate(X,L);
    //Tim vi tri phan tu dau tien co noi dung x
    //Doan lenh kiem tra ham Locate
    if (P==EndList(L))
        printf("\n\nKhong ton tai phan tu co noi dung %d trong danh sach",X);
    else
        printf("\n\nVi tri phan tu dau tien co noi dung %d trong danh sach la %d",X,P);
    return 0;
}