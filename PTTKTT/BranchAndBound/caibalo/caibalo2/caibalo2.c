#include<stdio.h>
#define SIZE 100

typedef struct{
    char DV[100];
    float TL, GT, DG;
    int PA, SL;
}Do_Vat;

int min(int a, int b){
    return a < b ? a : b;
}
void Swap(Do_Vat *a, Do_Vat *b){
    Do_Vat temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(Do_Vat dovat[], int n){
    Do_Vat lowkey;
    int i, j, lowindex;
    for(i = 0; i < n-1; i++){
        lowkey = dovat[i];
        lowindex = i;
        for(j = i+1; j < n; j++){
            if(lowkey.DG < dovat[j].DG){
                lowkey = dovat[j];
                lowindex = j;
            }
        }
        Swap(&dovat[lowindex], &dovat[i]);
    }
}
void ReadFile(Do_Vat dsdv[], int* n, int* W){
    FILE* f = freopen("caibalo2.txt", "r", stdin);
    int i = 0;
    scanf("%d", W);
    while(scanf("%f %f %d %[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].DV) != EOF){
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].PA = 0;
        i++;
    }
    *n = i;
    fclose(f);
}
void PrintFile(Do_Vat dsdv[], int n, int W){
    printf("\t\t\t---Bai toan cai ba lo 3 (nhanh can)---\n");
    printf("Tong trong luong: %d\n", W);
    printf("|---|------------------|---------|---------|---------|------|\n");
	printf("|STT|      Do Vat      |   TL    |    GT   |    DG   |  PA  |\n");
    printf("|---|------------------|---------|---------|---------|------|\n");
    int i;
    float TTL = 0, TGT = 0;
    for(i = 0; i < n; i++){
        printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d|\n",i+1, dsdv[i].DV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TTL += dsdv[i].TL*dsdv[i].PA;
        TGT += dsdv[i].GT*dsdv[i].PA;
    }
    printf("|---|------------------|---------|---------|---------|------|\n");
    printf("Phuong an X(");
    for(i = 0; i < n-1; i++){
        printf("%d, ", dsdv[i].PA);
    }
    printf("%d)\n", dsdv[n-1].PA);
    printf("Tong trong luong: %.2f\n", TTL);
    printf("Tong gia tri: %.2f", TGT);
}
void Tao_Nut_Goc(float W, float* TLConLai, float* CT, float* GLNTT, float* TGT, float DGLN){
    *TGT = 0.0;
    *TLConLai = W;
    *CT = *TLConLai*DGLN;
    *GLNTT = 0.0;
}
void Cap_Nhat_PA_TNTT(float TGT, float* GLNTT, int x[], Do_Vat *dsdv, int n){
    int i;
    if(*GLNTT < TGT){
        *GLNTT = TGT;
        for(i = 0; i < n; i++){
            dsdv[i].PA = x[i];
        }
    }
}
void Nhanh_Can(int i, float* TGT, float* CT, float* TLConLai, float *GLNTT, int x[], Do_Vat* dsdv, int n){
    int j; //So do vat duoc chon
    //Sua lai voi moi bai cai ba lo tuong ung
    int DVLN_co_the_chon = min(*TLConLai / dsdv[i].TL, dsdv[i].SL);
    for(j = DVLN_co_the_chon; j >= 0; j--){
        *TGT += j*dsdv[i].GT;
        *TLConLai -= j*dsdv[i].TL;
        *CT = *TGT + *TLConLai*dsdv[i+1].DG;
        if(*CT > *GLNTT){
            x[i] = j;
            if(i == n-1 || *TLConLai == 0.0)
                Cap_Nhat_PA_TNTT(*TGT, GLNTT, x, dsdv, n);
            else
                Nhanh_Can(i+1, TGT, CT, TLConLai, GLNTT, x, dsdv, n);
        }
        //Quay lui
        x[i] = 0;
        *TGT -= j*dsdv[i].GT;
        *TLConLai += j*dsdv[i].TL;
    }
}

int main(){
    int n, W;
    Do_Vat dsdv[SIZE];
    float TGT, TLConLai, GLNTT, CT;
    int x[SIZE];
    ReadFile(dsdv,&n,&W);
    SelectionSort(dsdv,n);
    Tao_Nut_Goc(W,&TLConLai,&CT,&GLNTT,&TGT,dsdv[0].DG);
    Nhanh_Can(0,&TGT,&CT,&TLConLai,&GLNTT,x,dsdv,n);
    PrintFile(dsdv,n,W);
}