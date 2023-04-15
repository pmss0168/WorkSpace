#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 100

typedef int Keytype;
typedef float Othertype;
typedef struct{
	Keytype key;
	Othertype otherfields;
}Recordtype;

void Swap(Recordtype *x, Recordtype *y){
	Recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void InsertionSort(Recordtype a[], int n){
	int i, j;
	for(i = 0; i < n; i++){
		j = i;
		while(j > 0 && a[j].key < a[j-1].key){
			Swap(&a[j], &a[j-1]);
			j--;
		}
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
	printf("---Thuat toan InsertionSort---\n");
	Recordtype a[MAX_ELEMENT];
	int n;
	ReadFile(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	PrintFile(a,n);
	
	InsertionSort(a, n);
	
	printf("Du lieu sau khi sap xep:\n");
	PrintFile(a,n);
	return 0;
}
