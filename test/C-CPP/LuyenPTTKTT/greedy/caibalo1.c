#include<stdio.h>

typedef struct{
    float TL, GT, DG;
    int PA;
    char DV[100];
}DoVat;

void ReadFile(DoVat dsdv[], int *n, int *W){
    FILE *f = freopen("caibalo1.txt", "r", stdin);
    scanf("%d", W);
    int i = 0;
    if(f == NULL){
        printf("Loi doc file!!!");
    }
    else{
        while(scanf("%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].DV) != EOF){
            dsdv[i].DG = dsdv[i].GT/dsdv[i].TL;
            dsdv[i].PA = 0;
            i++;
        }
    }
    fclose(f);
    *n = i;
}
void PrintFile(DoVat dsdv[], int n, int W){
    int i;
    float TGT = 0, TTL = 0;
    printf("Tong trong luong: %d\n", W);
    printf("|---|-------------------------|---------|---------|---------|------|\n");
    printf("|STT|          Ten            |   TL    |    GT   |   DG    |  PA  |\n");
    printf("|---|-------------------------|---------|---------|---------|------|\n");
    for(i = 0; i < n; i++){
        printf("|%2d |%-25s|%6.2f   |%6.2f   |%6.2f   |%3d   |\n", i+1, dsdv[i].DV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TTL += dsdv[i].TL*dsdv[i].PA;
        TGT += dsdv[i].GT*dsdv[i].PA;
    }
    printf("|---|-------------------------|---------|---------|---------|------|\n");
    printf("Phuong an X(");
    for(i = 0; i < n-1; i++)
        printf("%d,",dsdv[i].PA);
    printf("%d)\n",dsdv[n-1].PA);
    printf("Tong trong luong: %.2f\n", TTL);
    printf("Tong gia tri: %.2f\n", TGT);
}
void Swap(DoVat *x, DoVat *y){
    DoVat temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(DoVat a[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = n-1; j >= i+1; j--){
            if(a[j].DG > a[j-1].DG)
                Swap(&a[j],&a[j-1]);
        }
    }
}
// int min(int x, int y){
//     return x > y ? y : x;
// }
void Greedy(DoVat dsdv[], int n, int W){
    int i;
    for(i = 0; i < n; i++){
        dsdv[i].PA = W/dsdv[i].TL;
        W -= dsdv[i].TL*dsdv[i].PA;
    }
}
int main(){
    int n, W;
    DoVat dsdv[100];
    printf("\t\t\t---Bai toan cai balo1 (tham an)---\n");
    ReadFile(dsdv,&n,&W);
    BubbleSort(dsdv,n);
    Greedy(dsdv,n,W);
    PrintFile(dsdv,n,W);
    return 0;
}