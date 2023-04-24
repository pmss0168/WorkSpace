#include<stdio.h>

typedef struct{
	int key;
	float other;
}RecordType;

void Swap(RecordType *a, RecordType *b){
	RecordType temp = *a;
	*a = *b;
	*b = temp;
}
int FindPivot(RecordType a[], int head, int tail){
	int k = head+1, firstkey = a[head].key;
	while(k <= tail && a[k].key == firstkey)
		k++;
	if(k > tail) return -1;
	if(a[k].key > firstkey) return k;
	return head; 
}
int Partition(RecordType a[], int head, int tail, int pivot){
	int L = head, R = tail;
	while(L <= R){
		while(a[L].key < pivot)	L++;
		while(a[R].key >= pivot) R--;
		if(L < R)
			Swap(&a[L],&a[R]);
	}
	return L;
}
void QuickSort(RecordType a[], int head, int tail){
	int k, pivot, pivotindex;
	pivotindex = FindPivot(a,head,tail);
	if(pivotindex != -1){
		pivot = a[pivotindex].key;
		k = Partition(a,head,tail,pivot);
		QuickSort(a,head,k-1);
		QuickSort(a,k,tail);
	}
}
void ReadFile(RecordType a[], int *n){
	FILE *f = freopen("data.txt", "r", stdin);
	int i = 0;
	while(scanf("%d %f", &a[i].key, &a[i].other) != EOF){
		i++;
	}
	fclose(f);
	*n = i;
}
void PrintFile(RecordType a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%2d. %5d %-4.2f\n", i+1, a[i].key, a[i].other);
	}
}
int main(){
	int n;
	RecordType a[100];
	printf("\t\t\t---Thuat toan sap xep nhanh---\n");
	ReadFile(a,&n);
	printf("Danh sach truoc khi sap xep:\n");
	PrintFile(a,n);
	printf("Danh sach sau khi sap xep:\n");
	QuickSort(a,0,n-1);
	PrintFile(a,n);
	return 0;
}






















