#include<stdio.h>

typedef struct{
    int key;
    float other;
}RecordType;
void Swap(RecordType *x, RecordType *y){
    RecordType temp = *x;
    *x = *y;
    *y = temp;
}
void PushDown(RecordType a[], int first, int last){
    int r = first;
    while(r <= (last-1)/2){
        if(last == 2*r+1){
            if(a[r].key > a[last].key)
                Swap(&a[r],&a[last]);
            r = last;
        }
        else{
            if(a[r].key > a[2*r+1].key && a[2*r+1].key <= a[2*r+2].key){
                Swap(&a[r],&a[2*r+1]);
                r = 2*r+1;
            }
            else{
                if(a[r].key > a[2*r+2].key && a[2*r+1].key > a[2*r+2].key){
                    Swap(&a[r],&a[2*r+2]);
                    r = 2*r+2;
                }
                else
                    r = last;
            }
        }
    }
}
void HeapSort(RecordType a[], int n){
    int i;
    for(i = (n-1)/2; i >= 0; i--)
        PushDown(a,i,n-1);
    for(i = n-1; i >=2; i--){
        Swap(&a[0],&a[i]);
        PushDown(a,0,i-1);
    }
    Swap(&a[0],&a[1]);
}
void ReadFile(RecordType a[], int *n){
    FILE *f = freopen("data.txt", "r", stdin);
    int i = 0;
    if(f == NULL){
        printf("Loi file!!!");
    }
    else{
        while(scanf("%d %f", &a[i].key, &a[i].other) != EOF){
            i++;
        }
    }
    fclose(f);
    *n = i;
}
void PrintFile(RecordType a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%2d. %4d  %-5.2f\n", i+1, a[i].key, a[i].other);
    }
}
int main(){
    int n;
    RecordType a[100];
    printf("\t\t\t---Thuat toan vun dong---\n");
    ReadFile(a,&n);
    printf("Danh sach truoc khi sap xep:\n");
    PrintFile(a,n);
    printf("Danh sach sau khi sap xep:\n");
    HeapSort(a,n);
    PrintFile(a,n);
    return 0;
}