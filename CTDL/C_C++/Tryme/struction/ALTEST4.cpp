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
    printf("\nNhap noi dung can them\n");
    scanf("%d",&X);
    printf("\nNhap vi tri can them\n");
    scanf("%d,&P");
    //=================
    
    return 0;
}