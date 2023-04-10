#include <stdio.h>
#include <string.h>
#define Maxlength 40
struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
typedef int Position;
typedef struct
{
    SinhVien A[Maxlength];
    Position n;
} DanhSach;
//---------------------//
DanhSach dsRong()
{
    DanhSach L;
    L.n = 0;
    return L;
}
int tim(char x[10], DanhSach L)
{
    int P = 1;
    int found = 0;
    while (P != L.n + 1 && found == 0)
    {
        if (strcmp(L.A[P - 1].MSSV, x) == 0)
            found = 1;
        else
            P++;
    }
    return P;
}
void chenCuoi(struct SinhVien s, DanhSach *pL)
{
    if (pL->n == Maxlength)
        printf("Loi! Danh sach day!");
    else
    {
        pL->n++;
        pL->A[pL->n - 1] = s;
    }
}
// DanhSach nhap()
// {
//     DanhSach L;
//     struct SinhVien sv;
//     L = dsRong();
//     int N, i;
//     char ms[10];
//     char ht[50];
//     scanf("%d ", &N);
//     for (i = 1; i <= N; i++)
//     {
//         fgets(ms, 10, stdin);
//         if (ms[strlen(ms) - 1] == '\n')
//             ms[strlen(ms) - 1] = '\0';
//         strcpy(sv.MSSV, ms);
//         fgets(ht, 50, stdin);
//         if (ht[strlen(ht) - 1] == '\n')
//             ht[strlen(ht) - 1] = '\0';
//         strcpy(sv.HoTen, ht);
//         scanf("%f%f%f ", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);
//         if (tim(ms, L) == L.n + 1)
//         {
//             chenCuoi(sv, &L);
//         }
//     }
//     return L;
// }

void hienthiDat(DanhSach L)
{
    Position P = 1;
    while (P != L.n + 1)
    {
        if ((L.A[P - 1].DiemLT) + L.A[P - 1].DiemTH1 + L.A[P - 1].DiemTH2 >= 4)
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[P - 1].MSSV, L.A[P - 1].HoTen, L.A[P - 1].DiemLT, L.A[P - 1].DiemTH1, L.A[P - 1].DiemTH2);
        P++;
    }
}

void hienthi(DanhSach L)
{
    Position P = 1;
    while (P != L.n + 1)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[P - 1].MSSV, L.A[P - 1].HoTen, L.A[P - 1].DiemLT, L.A[P - 1].DiemTH1, L.A[P - 1].DiemTH2);
        P++;
    }
}
DanhSach nhap()
{
    DanhSach L;
    struct SinhVien sv;
    L = dsRong();
    int n;
    char ms[10];
    char ht[50];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fgets(ms, 10, stdin);
        if (ms[strlen(ms) - 1] == '\n')
            ms[strlen(ms) - 1] = '\0';
        strcpy(sv.MSSV, ms);
        fgets(ht, 50, stdin);
        if (ht[strlen(ht) - 1] == '\n')
            ht[strlen(ht) - 1] = '\0';
        strcpy(sv.HoTen, ht);
        scanf("%f%f%f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);
        if (tim(ms, L) == L.n + 1)
        {
            chenCuoi(sv, &L);
        }
    }
    return L;
}
int main()
{
    DanhSach L;
    L = nhap();
    hienthi(L);
    printf("Sinh vien Dat\n");
    hienthiDat(L);
}
