#include<stdio.h>
#define MAX_ELEMENTS 100


void ReadFile(int A[][100], int* n){
    FILE *f = fopen("NumberTriangle.txt" , "r");
    *n = 0;
    int i;
    while(!feof(f)){
        for(i = 0; i <= *n; i++)
            fscanf(f, "%d", &A[*n][i]);
        (*n)++;
    }
    fclose(f);    
}
void PrintFile(int A[][100], int F[][100], int PA[], int n){
    int i, j, tong = 0;
    printf("Tam giac so:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < i+1; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Bang so lieu F:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < i+1; j++){
            printf("%d ", F[i][j]);
        }
        printf("\n");
    }
    printf("Phuong An:\n");
    for(i = 0; i < n; i++){
        printf("%d ", PA[i]);
        tong += PA[i];
    }
    printf("\nTong gia tri cac so: %d", tong);
}
int CS_Max(int F[][100], int i, int j){
    if (j == 0)
        return (F[i - 1][0] > F[i - 1][1]) ? 0 : 1;
    if (j == i)
        return i - 1;
    if (j == i - 1)
        return (F[i - 1][i - 2] > F[i - 1][i - 1]) ? i - 2 : i - 1;
    if (F[i - 1][j - 1] > F[i - 1][j] && F[i - 1][j - 1] > F[i - 1][j + 1])
        return j - 1;
    if (F[i - 1][j] > F[i - 1][j - 1] && F[i - 1][j] > F[i - 1][j + 1])
        return j;
    if (F[i - 1][j + 1] > F[i - 1][j] && F[i - 1][j + 1] > F[i - 1][j - 1])
        return j + 1;   
}
int CS_MAX_Tail(int F[], int j){
    int maxkey = F[0];
    int maxindex = 0;
    int k;
    for(k = 0; k <= j; k++){
        if(F[k] > maxkey){
            maxkey = F[k];
            maxindex = k;
        }
    }
    return maxindex;
}
void Tao_Bang(int A[][100], int n, int F[][100]){
    int i, j;
    F[0][0] = A[0][0];
    F[1][0] = A[1][0] + F[0][0];
    F[1][1] = A[1][1] + F[0][0];
    for(i = 2; i < n; i++)
        for(j = 0; j < i+1; j++){
            int k = CS_Max(F,i,j);
            F[i][j] = A[i][j] + F[i-1][k];
        }
}
void Tra_Bang(int A[][100], int n, int F[][100], int PA[]){
    int i, j;
    j = CS_MAX_Tail(F[n-1],n-1);
    PA[n-1] = A[n-1][j];
    for(i = n; i >= 1; i--){
        j = CS_Max(F,i,j);
        PA[i-1] = A[i-1][j];
    }
}
int main(int argc, char const *argv[])
{
    int A[100][100];
    int F[100][100];
    int n;
    printf("\t\t\t---Bai toan tam giac so---\n");
    ReadFile(A,&n);
    int PA[100];
    Tao_Bang(A,n,F);
    Tra_Bang(A,n,F,PA);
    PrintFile(A,F,PA,n);
    return 0;
}
