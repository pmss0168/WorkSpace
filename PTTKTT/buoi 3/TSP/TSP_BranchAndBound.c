#include <stdio.h>

#define SIZE 100

typedef struct{
    float do_dai;
    int dau, cuoi;
    int da_dung;
} Canh;

float canh_NN(Canh a[][SIZE], int n){
    float Cmin = 3.40282e+38;
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != j && !a[i][j].da_dung && a[i][j].do_dai < Cmin)
                Cmin = a[i][j].do_dai;
    return Cmin;
}

float can_duoi(Canh a[][SIZE], float TGT, int n, int i){
    return TGT + (n - i) * canh_NN(a, n);
}

void Cap_Nhat_PA_TNTT(Canh a[][SIZE], int n, float TGT, float *GiaNNTT, Canh x[], Canh PA[]){
    int i;
    x[n - 1] = a[x[n - 2].cuoi][x[0].dau];
    TGT = TGT + x[n - 1].do_dai;
    if (*GiaNNTT > TGT){
        *GiaNNTT = TGT;
        for (i = 0; i < n; i++)
            PA[i] = x[i];
    }
}
int Chu_Trinh(Canh PA[], int k, int ke_tiep){
    int i = 0, co_CT = 0;
    while (i < k && !co_CT){
        if (ke_tiep == PA[i].dau)
            co_CT = 1;
        else
            i++;
    }
    return co_CT;
}
void Nhanh_Can(Canh a[][SIZE], int n, int i, int dau, float *TGT, float *CD, float *GiaNNTT, Canh x[], Canh PA[]){
    int j;
    for (j = 0; j < n; j++)

        if (dau != j && !a[dau][j].da_dung && !Chu_Trinh(x, i, j)){
            *TGT = *TGT + a[dau][j].do_dai;
            *CD = can_duoi(a, *TGT, n, i + 1);

            if (*CD < *GiaNNTT){
                x[i] = a[dau][j];
                a[dau][j].da_dung = 1;
                a[j][dau].da_dung = 1;

                if (i == n - 2)
                    Cap_Nhat_PA_TNTT(a, n, *TGT, GiaNNTT, x, PA);
                else
                    Nhanh_Can(a, n, i + 1, j, TGT, CD, GiaNNTT, x, PA);
            }
            *TGT = *TGT - a[dau][j].do_dai;
            a[dau][j].da_dung = a[j][dau].da_dung = 0;
        }
}
void ReadFile(Canh a[][SIZE], int *n){
    FILE *fi;
    fi = fopen("TSP1.txt", "r");
    int N;
    fscanf(fi, "%d", &N);
    *n = N;
    int i, j;
    for (i = 0; i < *n; i++){
        for (j = 0; j < *n; j++){
            fscanf(fi, "%f", &a[i][j].do_dai);
            a[i][j].dau = i;
            a[i][j].cuoi = j;
            a[i][j].da_dung = 0;
        }
    }
    fclose(fi);
}
void PrintFile(Canh a[][SIZE], Canh PA[], int start, int n){
    printf("Thuat Toan Branch And Bound\nBai Toan TSP\n");
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("[%c%c]= %3.2f ", a[i][j].dau + 65, a[i][j].cuoi + 65, a[i][j].do_dai);
        }
        printf("\n");
    }
    float sum = 0.0;
    printf("\nDuong di tu dinh %c -> %c", start + 65, n - 1 + 65);
    printf("\nPhuong an tim duoc: \n");
    for (i = 0; i < n; i++){
        sum += PA[i].do_dai;
        printf("[%c%c]= %3.2f\n", PA[i].dau + 65, PA[i].cuoi + 65, PA[i].do_dai);
    }
    printf("Tong do dai cac canh cua chu trinh la: %8.2f\n", sum);
}
int main(int argc, char const *argv[]){

    Canh a[SIZE][SIZE];
    int n;
    ReadFile(a, &n);
    float TGT = 0, CD = 0;
    float GiaNNTT = 3.40282e+38;
    Canh PA[n], x[n];
    char c;
    printf("Nhap thanh pho khoi thanh 1 -> %d (A -> %c)\n", (n - 1), (n - 1) + 65);
    scanf("%c", &c);
    if (c >= 97)
        c = c - 32;
    Nhanh_Can(a, n, 0, c - 65, &TGT, &CD, &GiaNNTT, x, PA);
    PrintFile(a, PA, c - 65, n);
    return 0;
}
