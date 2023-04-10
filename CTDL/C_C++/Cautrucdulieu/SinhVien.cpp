#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxlength 40
// typedef struct{
//     char mssv[10];
//     char hoten[50];
//     float dlt;
//     float dth1;
//     float dth2;
// }SinhVien;
struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};
typedef struct SinhVien ElementType;
typedef int Position;
typedef struct{
    ElementType A[Maxlength];
    Position n;
}DanhSach;
void makenullList(DanhSach *pL){
    pL->n = 0;
}
int emptyList(DanhSach L){
    return L.n == 0;
}
Position first(DanhSach L){
    return 1;
}
Position endList(DanhSach L){
    return L.n + 1;
}
Position next(Position P, DanhSach L){
    return P + 1;
}
Position previous(Position P, DanhSach L){
    return P + 1;
}
ElementType retrieve(Position P, DanhSach L){
    return L.A[P-1];
}
void insertList(ElementType X, Position P, DanhSach *pL){
    Position i=0;
    if (pL->n == P)
        printf("\n Danh sach day !!!");
    else 
        if ((P<1)||(P>pL->n+1))
            printf("\n Vi tri khong hop le !!!");
        else {
                for (i=pL->n; i>=P; --i)
                    pL->A[i]=pL->A[i-1];
                pL->n++;
                pL->A[P-1]= X;
        }
}
void deleteList(Position P, DanhSach *pL){
    if ((P>pL->n)||(P<1))
        printf("\n Vi tri khong hop le !!!");
    else 
        if (emptyList(*pL))
            printf("\n Danh sach rong");
        else{
            Position i;
            for (i=P; i<pL->n; ++i)
                pL->A[i-1] = pL->A[i];
            pL->n--;
        }
}
DanhSach nhap(){
    DanhSach L;
    char hoten[50], mssv[10];
    float diemlt, diemth1, diemth2;
    makenullList(&L);
    int n,i;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i){
        ElementType X;
        scanf("\n");
        fgets(mssv,sizeof(mssv)+1,stdin);
        int k = strlen(mssv);
        if(mssv[k+1] == '\n') mssv[k+1] = '\0';
        strcpy(X.MSSV,mssv);
        fgets(hoten,sizeof(hoten)+1,stdin);
        k = strlen(hoten);
        if(hoten[k+1] == '\n') hoten[k+1] = '\0';
        strcpy(X.HoTen,hoten);
        scanf("%f", &diemlt);
         X.DiemLT = diemlt;
        scanf("%f", &diemth1);
        X.DiemTH1 = diemth1;
        scanf("%f", &diemth2);
        X.DiemTH2 = diemth2;
        insertList(X,L.n+1,&L);
        //printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
    return L;
}
void hienthi(DanhSach L){
    double tongdiem = 0;
    Position P = 1;
    while (P != endList(L)){
        tongdiem = L.A[P-1].DiemLT + L.A[P-1].DiemTH1 + L.A[P-1].DiemTH2;
        printf("%s - %s - %.2f - %.2f - %.2f - %.2lf\n",L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2, tongdiem);
        P++;
    }
    
}
void hienthiDat(DanhSach L){
    double tongdiem = 0;
    Position P = 1;
    while (P != endList(L)){
        tongdiem = L.A[P-1].DiemLT + L.A[P-1].DiemTH1 + L.A[P-1].DiemTH2;
        if(tongdiem >= 4.0)
            printf("%s - %s - %.2f - %.2f - %.2f - %.2lf\n",L.A[P-1].MSSV, L.A[P-1].HoTen, L.A[P-1].DiemLT, L.A[P-1].DiemTH1, L.A[P-1].DiemTH2, tongdiem);
        P++;
    }
    
}
DanhSach dsRong(){
    DanhSach L;
    makenullList(&L);
    return L;
}
void chenCuoi(ElementType X, DanhSach *pL){
    Position P = pL->n;
    if (Maxlength == P)
        printf("Loi! Danh sach day!");
    else{
            pL->n++;
            pL->A[P] = X;
        }
}
Position tim(char X[10], DanhSach L){
    Position I = 1;
    while(I != L.n + 1){
        if (X == L.A[I-1].MSSV) return I;
    }
    return L.n + 1;
}
int main(int argc, char const *argv[]){
    DanhSach L;
    L.n=40;
    struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 2.0f};
    chenCuoi(s, &L);
    return 0;
}
