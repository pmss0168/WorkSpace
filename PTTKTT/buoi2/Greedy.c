#include<stdio.h>
#define MAX_ELEMENT 100

typedef int Keytype;
typedef char Othertype;
typedef struct{
	Othertype Moneyname[MAX_ELEMENT];
	Keytype MG, PA;
}Moneytype;

void Swap(Moneytype* x, Moneytype* y){
	Moneytype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(Moneytype a[], int n){
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = n -1; j >= i+1; j--){
			if(a[j].MG > a[j-1].MG)
				Swap(&a[j], &a[j-1]);
		}
	}
}

void ReadFile(Moneytype a[], int *n){
	FILE *f = fopen("ATM.txt", "r");
	int i = 0;
	if(f != NULL){
		while(fscanf(f, "%d%[^\n]", &a[i].MG, &a[i].Moneyname) != EOF){
			a[i].PA = 0;
			i++;
		}
	}else{
		printf("Loi file\n");
		return;
	}

	*n = i;
	fclose(f);
}



void Greedy(Moneytype a[], int n, int *TienCanRut){
	int i = 0;
	BubbleSort(a,n);
	while(i < n && *TienCanRut > 0){
		a[i].PA = *TienCanRut / a[i].MG;
		*TienCanRut = *TienCanRut - (a[i].PA * a[i].MG);
		i++;
	}
}
void PrintFile(Moneytype a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%3d. So to tien can rut %4d %8d %30s\n", i+1, a[i].PA, a[i].MG, a[i].Moneyname);
	}
}
int main(){
	Moneytype a[MAX_ELEMENT];
	int n;
	int Sotiencanrut;
	ReadFile(a,&n);
	printf("Nhap so tien can rut:");
	scanf("%d", &Sotiencanrut);
	Greedy(a,n,&Sotiencanrut);
	PrintFile(a,n);
    printf("So tien con lai khong the rut: %6d", Sotiencanrut);
	return 0;
}
