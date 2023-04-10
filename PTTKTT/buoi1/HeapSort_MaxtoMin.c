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

void PushDown(Recordtype a[], int first, int last){
	int r = first;
	while(r <= (last-1)/2)
		if(last == 2*r+1){
			if(a[r].key > a[last].key)
				Swap(&a[r], &a[last]);
			r = last;
		}
		else{
			if(a[r].key > a[2*r+1].key && a[2*r+1].key <= a[2*r+2].key){
				Swap(&a[r], &a[2*r+1]);
				r = 2*r+1;
			}
			else{
				if(a[r].key > a[2*r+2].key){
					Swap(&a[r], &a[2*r+2]);
					r = 2*r+2;
				}
				else
					r = last;
			}
		}
}

void HeapSort(Recordtype a[], int n){
	int i;
	for(i = (n-2)/2; i >= 0; i--)
		PushDown(a,i, n-1);
	for(i = n-1; i >= 2; i--){
		Swap(&a[0], &a[i]);
		PushDown(a,0, i-1);
	}
	Swap(&a[0], &a[1]);
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
	
	HeapSort(a,n);
	
	printf("Du lieu sau khi sap xep:\n");
	PrintFile(a,n);
	return 0;
}
