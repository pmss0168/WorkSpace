#include <stdio.h>
#include <conio.h>
#include <D:\Wordspace\C_C++\Tryme\struction\ALISTLIB.cpp>

int main(){
    List L;
    MakeNull_List(&L);
    printf("\n\n Danh sach sau khi khoi tao rong la ");
    if(Empty_List(L)) printf("\n\n Danh sach rong ");
    else printf("\n\n Danh sach khong rong ");
    for (int i=1; i<=5; i++){
        Insert_List(i+10,EndList(L),&L);
    }
    printf("\n\n Danh sach sau khi dua cac so thu 11 - 15 vao theo thu tu la \n\n ");
    Print_List(L);
    getch();
}
