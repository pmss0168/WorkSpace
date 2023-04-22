#include<stdio.h>

typedef struct{
    float length;
    int head, tail;
}Edge;

void Swap(Edge *a, Edge *b){
    Edge temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(Edge ds[], int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = n-1; j >= i+1; j--){
            if(ds[j].length < ds[j-1].length)
                Swap(&ds[j],&ds[j-1]);
        }
    }
}
void ReadFile(Edge ds[], int *n){
    FILE* f = fopen("TSP.txt", "r");
    int i, j, t, k = 0;
    float temp;
    fscanf(f, "%d", n);
    for(i = 0; i < *n; i++){
        for(j = i; j < *n; j++){
            if(i == j){
                for(t = 0; t <= j; t++)
                    fscanf(f, "%f", &temp);
            }
            else{
                fscanf(f, "%f", &ds[k].length);
                ds[k].head = i;
                ds[k].tail = j;
                k++;
            }
        }
    }
    fclose(f); 
}
void PrintFile(Edge ds[], int n, int is_PA){
    int i;
    float tong = 0.0;
    for(i = 0; i < n; i++){
        printf("%3d  %c%c = %8.2f\n", i+1, ds[i].head+97, ds[i].tail+97, ds[i].length);
        if(is_PA)
            tong += ds[i].length;
    }
    if(is_PA)
        printf("Tong do dai cac canh: %5.2f", tong);
}
int dinh_cap3(Edge PA[], int k, Edge new){
    int i = 0, dem = 0;
    while(i < k && dem < 2){
        if(new.head == PA[i].head || new.head == PA[i].tail)
            dem++;
        i++;
    }
    if(dem == 2)
        return 1;
    i = 0;
    dem = 0;
    while(i < k && dem < 2){
        if(new.tail == PA[i].head || new.tail == PA[i].tail)
            dem++;
        i++;
    }
    return dem;
}
void init_forest(int parent[], int n){
    int i;
    for(i = 0; i < n; i++)
        parent[i] = i;
}
int find_root(int parent[], int u){
    while(u != parent[u])
        u = parent[u];
    return u;
}
void update_forest(int parent[], int r1, int r2){
    parent[r1] = r2;
}
int chu_trinh(int r_head, int r_tail){
    return r_head == r_tail;
}
void greedy(Edge list[], int n, Edge PA[]){
	int i, j, parent[n];
    init_forest(parent, n);
    int r_head, r_tail;
    j =0;
    for(i = 0; i < n*(n-1)/2; i++){
        r_head = find_root(parent, list[i].head);
        r_tail = find_root(parent, list[i].tail);
        if(!dinh_cap3(PA,j,list[i]) && !chu_trinh(r_head,r_tail)){
            PA[j++] = list[i];
            update_forest(parent,r_head,r_tail);
        }
    }
    for(; i < n*(n-1)/2; i++){
        r_head = find_root(parent, list[i].head);
        r_tail = find_root(parent, list[i].tail);
        if(!dinh_cap3(PA,n-1,list[i]) && !chu_trinh(r_head,r_tail)){
            PA[n-1] = list[i];
            break;
        }
    }
}

int main(){
	Edge list[100];
	int n;
	printf("\t\t\t--- Bai toan duong di cua nguoi giao hang (TSP)---\n");
	ReadFile(list,&n);
	printf("Danh sach cac canh cua do thi\n");
	PrintFile(list, n*(n-1)/2, 0);
	BubbleSort(list, n*(n-1)/2);
	printf("\nDanh sach cac canh cua do thi da sap xep\n");
	PrintFile(list, n*(n-1)/2, 0);
	Edge PA[n];
	greedy(list, n, PA);
	printf("PHUONG AN\n");
	PrintFile(list, n, 1);	
	return 0;
}
