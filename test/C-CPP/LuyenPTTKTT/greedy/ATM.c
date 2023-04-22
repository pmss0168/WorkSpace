#include<stdio.h>

typedef struct{
    int MG,PA;
    char Ten[50];
}MoneyType;
void Swap(MoneyType* a, MoneyType* b){
    MoneyType temp = *a;
    *a = *b;
    *b = temp;
}
void InsertionSort(MoneyType ds[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        j = i;
        while(j > 0 && ds[j].MG > ds[j-1].MG){
            Swap(&ds[j],&ds[j-1]);
            j--;
        }
    }
}
void ReadFile(MoneyType ds[], int *n){
    FILE *f = fopen("ATM.txt", "r");
    int i = 0;
    while(!feof(f)){
        fscanf(f, "%d %[^\n]", &ds[i].MG, &ds[i].Ten);
        ds[i].PA = 0;
        i++;
    }
    *n = i;
    fclose(f);
}
void PrintFile(MoneyType ds[], int n, int Tiencanrut){
    int i, tong = 0;
    for(i = 0; i < n; i++){
        printf("%2d. %6d %-25s %2d\n", i+1, ds[i].MG, ds[i].Ten, ds[i].PA);
        tong += ds[i].PA*ds[i].MG;
    }
    printf("So tien ban co the rut la: %d\n", tong);
    printf("So tien con lai: %d\n", Tiencanrut);
}
void Greedy(MoneyType ds[], int n, int *Tiencanrut){
    int i;
    for(i = 0; i < n; i++){
        ds[i].PA = *Tiencanrut/ds[i].MG;
        *Tiencanrut -= ds[i].PA*ds[i].MG;
    }
}
int main(){
    int n, Tiencanrut;
    MoneyType ds[100];
    printf("\t\t\t---Bai toan ATM---\n");
    printf("Moi nhap vao so tien can rut: \n");
    scanf("%d", &Tiencanrut);
    ReadFile(ds,&n);
    InsertionSort(ds,n);
    Greedy(ds,n,&Tiencanrut);
    PrintFile(ds,n,Tiencanrut);
    return 0;
}