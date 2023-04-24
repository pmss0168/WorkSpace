#include<stdio.h>

typedef struct{
    char DV[50];
    int PA, TL, GT;
}DoVat;
typedef int Bang[100][100];

void ReadFile(DoVat dsdv[], int *n, int *W){
    FILE *f = freopen("caibalo1.txt", "r", stdin);
    scanf("%d", W);
    int i = 0;
    if(f == NULL)
        printf("Loi file!!!\n");
    else{
        while(scanf("%d %d %[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].DV) != EOF){
            dsdv[i].PA = 0;
            i++;
        }
    }
    *n = i;
    fclose(f);
}
void PrintFile(DoVat dsdv[], int n, int W, Bang F, Bang X){
    int i, j, TGT = 0, TTL = 0;
    printf("Tong tron luong: %d\n", W);
    printf("|---|------------------------|---------|---------|------|\n");
    printf("|STT|           Ten          |    TL   |    GT   |  PA  |\n");
    printf("|---|------------------------|---------|---------|------|\n");
    for(i = 0; i < n; i++){
        printf("|%2d |%-24s|%5d    |%5d    |%3d   |\n",i+1, dsdv[i].DV, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
        TGT += dsdv[i].GT*dsdv[i].PA;
        TTL += dsdv[i].TL*dsdv[i].PA;
    }
    printf("|---|------------------------|---------|---------|------|\n");
    printf("Bang so lieu:\n");
    for(i = 0; i <= W; i++){
        printf("   %d  ",i);
    }
    printf("\n");
    for(i = 0; i < n; i++){
        printf("%d. ",i);
        for(j = 0; j <= W; j++){
            printf("|%2d %2d",F[i][j],X[i][j]);
        }
        printf("|\n");
    }
    printf("Phuong an: X(");
    for(i = 0; i < n-1; i++){
        printf("%d,", dsdv[i].PA);
    }
    printf("%d)\n", dsdv[n-1].PA);
    printf("Tong gia tri: %d\n", TGT);
    printf("Tong trong luong: %d", TTL);
}
int min(int x, int y){
    return x < y ? x : y;
}
void Tao_Bang(DoVat dsdv[], int n, int W, Bang F, Bang X){
    int xk,yk,k,Fmax,Xmax,V;
    for(V = 0; V <= W; V++){
        X[0][V] = V/dsdv[0].TL;
        F[0][V] = X[0][V]*dsdv[0].GT;
    }
    for(k = 1; k < n; k++){
        for(V = 0; V <= W; V++){
            Fmax = F[k-1][V];
            Xmax = 0;
            yk = V/dsdv[k].TL;
            for(xk = 1; xk <= yk; xk++){
                if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT > Fmax){
                    Fmax = F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
                    Xmax = xk;
                }
            }
            F[k][V] = Fmax;
            X[k][V] = Xmax;
        }
    }
}
void Tra_Bang(DoVat dsdv[], int n, int W, Bang X){
    int k, V = W;
    for(k = n-1; k >=0; k--){
        dsdv[k].PA = X[k][V];
        V -= X[k][V]*dsdv[k].TL;
    }
}
int main(){
    int n, W;
    DoVat dsdv[100];
    Bang F,X;
    printf("\t\t\t---Thuat toan cai balo (quy hoach dong)---\n");
    ReadFile(dsdv,&n,&W);
    Tao_Bang(dsdv,n,W,F,X);
    Tra_Bang(dsdv,n,W,X);
    PrintFile(dsdv,n,W,F,X);
    return 0;
}