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
void InsertionSort(DataType a[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        j = i;
        while(j > 0 && a[j].key < a[j-1].key){
            Swap(&a[j],&a[j-1]);
            j--;
        }
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
    printf("\t\t\t--Thuat toan sap xep xen---\n");
    ReadFile(a,&n);
    printf("Du lieu truoc khi sap xep:\n");
    PrintFile(a,n);
    printf("Du lieu sau khi sap xep:\n");
    InsertionSort(a,n);
    PrintFile(a,n);
    return 0;
}
