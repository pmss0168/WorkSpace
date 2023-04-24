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
void SelectionSort(DataType a[], int n){
    int i, j, lowindex, lowkey;
    for(i = 0; i < n-1; i++){
        lowkey = a[i].key;
        lowindex = i;
        for(j = i+1; j < n; j++){
            if(a[j].key < lowkey){
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        Swap(&a[i],&a[lowindex]);
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
    printf("\t\t\t--Thuat toan sap xep chon---\n");
    ReadFile(a,&n);
    printf("Du lieu truoc khi sap xep:\n");
    PrintFile(a,n);
    printf("Du lieu sau khi sap xep:\n");
    SelectionSort(a,n);
    PrintFile(a,n);
    return 0;
}
