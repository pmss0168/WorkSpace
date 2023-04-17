#include<stdio.h>
#define size 100;

typedef struct{
    int key;
    float other;
}DataType;

void Swap(DataType *a, DataType *b){
    DataType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int FindPivot(DataType a[], int i, int j){
    int firstkey, k;
    k = i+1;
    firstkey = a[i].key;
    while(k <= j && a[k].key == firstkey)
        k++;
    if(k > j)
        return -1;
    if(a[k].key > firstkey)
        return k;
    return i;
}
int Partition(DataType a[], int i, int j, int pivot){
    int L = i, R = j;
    while(L <= R){
        while(a[L].key < pivot) L++;
        while(a[R].key >= pivot) R--;
        if(L < R)
            Swap(&a[L],&a[R]);
    }
    return L;
}
void QuickSort(DataType a[], int i, int j){
    int pivot, pivotindex, k;
    pivotindex = FindPivot(a,i,j);
    if(pivotindex != -1){
        pivot = a[pivotindex].key;
        k = Partition(a,i,j,pivot);
        QuickSort(a,i,k-1);
        QuickSort(a,k,j);
    }    
}
void ReadFile(DataType a[], int *n){
    FILE *f = fopen("data.txt", "r");
    int i = 0;
    if(f == NULL)
        printf("Loi File!!!");
    else{
        while(!feof(f)){
            fscanf(f, "%d%f",&a[i].key, &a[i].other);
            i++;
        }
        *n = i;
        fclose(f);
    }
}
void PrintFile(DataType a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%3d  %-5.2f\n", a[i].key, a[i].other);
    }
}
int main(){
    int n;
    DataType a[100];
    printf("\t\t\t--Thuat toan sap xep nhanh---\n");
    ReadFile(a,&n);
    printf("Du lieu truoc khi sap xep:\n");
    PrintFile(a,n);
    printf("Du lieu sau khi sap xep:\n");
    QuickSort(a,0,n-1);
    PrintFile(a,n);
    return 0;
}
