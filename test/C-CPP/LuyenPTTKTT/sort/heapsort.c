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
void PushDown(DataType a[], int first, int last){
    int r = first;
    while(r <= (last-1)/2){
        if(last == 2*r+1){
            if(a[r].key < a[last].key)
                Swap(&a[r],&a[last]);
            r = last;
        }
        else{
            if(a[r].key < a[r*2+1].key && a[r*2+1].key >= a[r*2+2].key){
                Swap(&a[r],&a[r*2+1]);
                r = 2*r+1;
            }
            else{
                if(a[r].key < a[r*2+2].key){
                    Swap(&a[r],&a[r*2+2]);
                    r = r*2+2;
                }
                else
                    r = last;
            }
        }
    }
}
void HeapSort(DataType a[], int n){
    int i;
    for(i = (n-2)/2; i >= 0; i--){
        PushDown(a,i,n-1);
    }
    for(i = n; i >= 2; i--){
        Swap(&a[0],&a[i]);
        PushDown(a,0,i-1);
    }
    Swap(&a[0],&a[1]);
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
    printf("\t\t\t--Thuat toan sap xep vun dong---\n");
    ReadFile(a,&n);
    printf("Du lieu truoc khi sap xep:\n");
    PrintFile(a,n);
    printf("Du lieu sau khi sap xep:\n");
    HeapSort(a,n);
    PrintFile(a,n);
    return 0;
}
