#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 100

typedef int Keytype;
typedef float Othertype;
typedef struct{
	Keytype key;
	Othertype otherfields;
}Recordtype;

void Swap(Recordtype* x, Recordtype* y){
	Recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(Recordtype a[], int i, int j){
	int L, R;
	Keytype pivot = a[i].key;
	L = i+1;
	R = j;
	while(L <= R){
		while(a[L].key <= pivot)
			L++;
		while(a[R].key > pivot)
			R--;
		if(L < R)
			Swap(&a[L], &a[R]);
	}
	Swap(&a[R], &a[i]);		//Dua chot vao vi tri diem giua
	return R;
}

void QuickSort(Recordtype a[], int i, int j){
	if(i < j){
		int k = Partition(a,i,j);
		QuickSort(a,i,k-1);
		QuickSort(a,k+1,j);
	}
}

void ReadFile(Recordtype a[], int *n){
	FILE *f;
	f = fopen("data.txt", "r");
	Recordtype temp;
	int i = 0;
	if(f!=NULL){
		while(fscanf(f, "%d %f", &temp.key, &temp.otherfields) != EOF){
			a[i].key = temp.key;
			a[i].otherfields = temp.otherfields;
			i++;
		}
	}
	else
		printf("Loi file\n");
	fclose(f);
	*n = i;
}

void PrintFile(Recordtype a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
	}
}

int main(){
	printf("---Thuat toan QuickSort---\n");
	Recordtype a[MAX_ELEMENT];
	int n;
	ReadFile(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	PrintFile(a,n);
	
	QuickSort(a,0,n-1);
	
	printf("Du lieu sau khi sap xep:\n");
	PrintFile(a,n);
	return 0;
}
