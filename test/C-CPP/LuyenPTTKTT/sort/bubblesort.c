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
void BubbleSort(DataType a[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = n-1; j >= i+1; j--){
            if(a[j].key < a[j-1].key){
                Swap(&a[j],&a[j-1]);
            }
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
    printf("\t\t\t--Thuat toan sap xep noi bot---\n");
    ReadFile(a,&n);
    printf("Du lieu truoc khi sap xep:\n");
    PrintFile(a,n);
    printf("Du lieu sau khi sap xep:\n");
    BubbleSort(a,n);
    PrintFile(a,n);
    return 0;
}
