/*===============bai tap=================*/
#include <stdio.h>
#include <stdlib.h>
#define SoPhanTu 100

typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
}NganXep;
void khoitao(NganXep *pS){
    pS->Dinh = SoPhanTu;
}
int ktRong(NganXep S){
    return S.Dinh == SoPhanTu;
}
int ktDay(NganXep S){
    return S.Dinh == 0;
}
void xoa(NganXep *pS){
    if(!(pS->Dinh == SoPhanTu))
        pS->Dinh++;
}
int giatriDinh(NganXep S){
    if (!(ktRong(S))){
        return S.DuLieu[S.Dinh];
    }   
    return 0;
}
void them(int x, NganXep *pS){
    
    if(!ktDay(*pS)){
        pS->Dinh -= 1;
        pS->DuLieu[pS->Dinh] = x;
    }
}
void hienthi(NganXep *pS){
    while (!ktRong(*pS))
    {
        printf("%d ", giatriDinh(*pS));
        xoa(pS);
    }
    
}
void doiNhiPhan(int n, NganXep *pS){
    khoitao(pS);
    while (n != 0)
    {
        them((int)n % 2, pS);
        n = n / 2;
    }
    
}
int main(int argc, char const *argv[]){
    NganXep S;
    int n;
    scanf("%d", &n);
    doiNhiPhan(n, &S);
    hienthi(&S);
    return 0;
}
