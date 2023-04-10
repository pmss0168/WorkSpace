#include <stdio.h>
#include <conio.h>
#include <D:\Wordspace\C_C++\Tryme\struction\Thuvien\ALISTLIB.h>
int main(){
    List L;
    MakeNull_List(&L);
    printf("\n\n Nhap danh sach tu ban phim ");
    Read_List(&L);
    printf("\n\n Danh sach vua nhap la: \n");
    Print_List(L);
    return 0;
}