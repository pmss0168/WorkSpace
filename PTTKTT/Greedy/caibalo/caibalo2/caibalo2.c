#include<stdio.h>

typedef struct {
	char DV[50];
	int  PA, SL;
	float TL, GT, DG;
}Do_Vat;

void Swap(Do_Vat* a, Do_Vat* b){
	Do_Vat temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(Do_Vat E[], int n){
	int i, j;
	for(i = 0; i < n-1; i++)
		for(j = n-1; j >= i+1; j--)
			if(E[j].DG > E[j-1].DG)
				Swap(&E[j], &E[j-1]);
}
int min(int a, int b){
	return a < b ? a : b;
}
void ReadFile(Do_Vat E[], int *n, float *W){
	FILE *f = freopen("caibalo2.txt", "r", stdin);
	int i = 0;
	if(f == NULL)
		printf("Loi doc file!!");
	else{
		
		scanf("%f", W);
		while(scanf("%f %f %d %[^\n]", &E[i].TL, &E[i].GT, &E[i].SL, &E[i].DV) != EOF){
			E[i].DG = E[i].GT / E[i].TL;
			E[i].PA = 0;
			i++;
		}
		*n = i;
	}
	fclose(f);
}
void PrintFile(Do_Vat E[], int n, float W){
	int i;
	float SUM_GT = 0.0, SUM_TL = 0.0;
	printf("\t\t\t---Bai toan cai ba lo 2 (tham an)---\n");
	printf("Trong luong tong: %-9.2f\n", W);
	printf("|---|------------------|---------|---------|---------|------|\n");
	printf("|STT|      Do Vat      |   TL    |    GT   |    DG   |  PA  |\n");
	printf("|---|------------------|---------|---------|---------|------|\n");
	for(i = 0; i < n; i++){
		printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d|\n", i+1, E[i].DV, E[i].TL, E[i].GT, E[i].DG, E[i].PA);
		SUM_TL += E[i].TL*E[i].PA;
		SUM_GT += E[i].GT*E[i].PA;
	}
	printf("|---|------------------|---------|---------|---------|------|\n");
	printf("Phuong an X(");
	for(i = 0; i < n-1; i++){
		printf("%d,", E[i].PA);
	}
	printf("%d)\n", E[n-1].PA);
	
	printf("Tong trong luong: %-9.2f\n", SUM_TL);
	printf("Tong gia tri: %-9.2f", SUM_GT);
}
void Greedy(Do_Vat E[], int n, float W){
    int i;
    BubbleSort(E, n);
    for (i = 0; i < n; i++){
        E[i].PA = min(W / E[i].TL, E[i].SL);
        W -= E[i].TL*E[i].PA;
    }
}

int main(){
	int n;
	float W;
	Do_Vat ds[100];
	ReadFile(ds,&n,&W);
	Greedy(ds,n,W);
	PrintFile(ds,n,W);
	return 0;
}

















