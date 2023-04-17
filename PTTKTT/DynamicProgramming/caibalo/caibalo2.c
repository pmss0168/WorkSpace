#include<stdio.h>

typedef struct {
    char DV[50];
    int PA, TL, GT, SL;
}Do_Vat;
typedef int Bang[100][100];

void ReadFile(Do_Vat dsdv[], int* n, int* W){
    FILE* f = freopen("caibalo2.txt", "r", stdin);
    int i = 0;
    scanf("%d", W);
    while(scanf("%d %d %d %[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].DV) != EOF){
        dsdv[i].PA = 0;
        i++;
    }
    *n = i;
    fclose(f);
}
void PrintFile(Do_Vat dsdv[], int n, int W, Bang F, Bang X){
    int i, j, TGT = 0, TTL = 0;
    printf("Bang so lieu da cho:\n");
    printf("Trong luong ba lo: %d\n", W);
    printf("|---|------------------|---------|---------|------|\n");
	printf("|STT|      Do Vat      |   TL    |    GT   |  PA  |\n");
    printf("|---|------------------|---------|---------|------|\n");
    for(i = 0; i < n; i++){
        printf("|%2d |%-18s|%5d    |%5d    |%4d  |\n",i+1, dsdv[i].DV, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
        TTL += dsdv[i].TL*dsdv[i].PA;
        TGT += dsdv[i].GT*dsdv[i].PA;
    }
    printf("|---|------------------|---------|---------|------|\n");
    printf("Bang gia so lieu [F,X]:\n");
    printf("k\\V   ");
    for(j = 0; j <= W; j++){
        printf("%d     ", j);
    }
    printf("\n");
    for(i = 0; i < n; i++){
        printf("%d. ",i+1);
        for(j = 0; j <= W; j++){
            printf("|%2d %2d", F[i][j], X[i][j]);
        }
        printf("|\n");
        printf("----------------------------------------------------------------\n");
    }
    printf("Phuong an: X(");
    for(i = 0; i < n-1; i++){
        printf("%d,", dsdv[i].PA);
    }
    printf("%d)\n", dsdv[n-1].PA);
    printf("Tong gia tri: %d\n", TGT);
    printf("Tong trong luong: %d", TTL);
}
int min(int a, int b){
    return a < b ? a : b;
}
//X so luong do vat k duoc chon
//F tong gia tri k do vat da duoc chon
void Tao_Bang(Do_Vat dsdv[], int n, int W, Bang F, Bang X){   
    int xk, yk, k, FMax, XMax, V;
	// Dien dong dau tien cua hai bang
 	for(V= 0; V<=W; V++) {
 		X[0][V] = min(V/dsdv[0].TL,dsdv[0].SL);
 		F[0][V] = X[0][V] * dsdv[0].GT;
 	}
	
	// �ien c�c d�ng c�n lai
	 for(k= 1; k<n; k++)
		 for(V=0; V<=W; V++) {
			 FMax = F[k-1][V] ;
			 XMax = 0;
			 yk = min(V/dsdv[k].TL,dsdv[k].SL);
			 for(xk = 1; xk<=yk; xk++)
			 	if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>FMax){
			 		FMax=F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
			 		XMax= xk;
			 		}
			 F[k][V] = FMax;
			 X[k][V] = XMax;
	 	}
}
void Tra_Bang(Do_Vat dsdv[], int n, int W, Bang X){
    int k, V = W;
    for(k = n-1; k >= 0; k--){
        dsdv[k].PA = X[k][V];
        V = V-X[k][V]*dsdv[k].TL;
    }
}
int main(){
    int n, W;
    Do_Vat dsdv[100];
    Bang F, X;
    printf("\t\t\t---Bai toan cai balo 2 (quy hoach dong)---\n");
    ReadFile(dsdv,&n,&W);
    Tao_Bang(dsdv,n,W,F,X);
    Tra_Bang(dsdv,n,W,X);
    PrintFile(dsdv,n,W,F,X);
    return 0;
}