  #include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct {
	float do_dai;
	int dau, cuoi;
}Canh;

void swap(Canh* x, Canh* y){
	Canh temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(Canh a[], int n){
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = n -1; j >= i+1; j--){
			if(a[j].do_dai < a[j-1].do_dai)
				swap(&a[j], &a[j-1]);
		}
	}
}

void read_file(Canh a[], int *n){
	FILE *f = freopen("TSP.txt", "r", stdin);
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
				fscanf(f, "%f ", &a[k].do_dai);
				a[k].dau = i;
				a[k].cuoi = j;
				k++;
			}
		}
	}
	fclose(f);
}

void print_file(Canh a[], int n, int la_PA){
	int i;
	float tong = 0.0;
	for(i = 0; i < n; i++){
		printf("%3d %c%c = %8.2f\n", i+1, a[i].dau+97, a[i].cuoi+97, a[i].do_dai);
		if(la_PA)
			tong += a[i].do_dai;
	}
	if(la_PA)
		printf("Tong do dai cac canh: %5.2f", tong);
}

int dinh_cap3(Canh PA[], int k, Canh new){
	int i = 0, dem = 0;
	//Kiem tra dinh dau cau canh moi co trung 2 lan
	while(i < k && dem < 2){
		if(new.dau == PA[i].dau || new.dau == PA[i].cuoi)
			dem++;
		i++;
	}
	if(dem == 2) return 1;
	i = 0; dem = 0;
	while(i < k && dem < 2){
		if(new.cuoi == PA[i].dau || new.cuoi == PA[i].cuoi)
			dem++;
		i++;
	}
	return dem == 2;
}

void init_forest(int parent[], int n){
	int i;
	for(i = 0; i < n; i++){
		parent[i] = i;
	}
}

int find_root(int parent[], int u){
	while(u != parent[u])
		u = parent[u];
	return u;	
}

int chu_trinh(int r_dau, int r_cuoi){
	return r_dau == r_cuoi;
}

void update_forest(int parent[], int r1, int r2){
	parent[r2] = r1;
}

void greedy(Canh list[], int n, Canh PA[]){
	int i, j, parent[n];
	init_forest(parent, n);
	int r_dau, r_cuoi;
	//Chon canh nho nhat khong tao thanh dinh cap 3 va khong tao chu trinh thieu
	j = 0;
	for(i = 0; i < n*(n-1)/2; i++){
		r_dau = find_root(parent, list[i].dau);
		r_cuoi = find_root(parent, list[i].cuoi);
		if(!dinh_cap3(PA, j, list[i]) && !chu_trinh(r_dau, r_cuoi)){
			PA[j++] = list[i];
			update_forest(parent, r_dau, r_cuoi); 
		}
	}
	//Tim canh cuoi cung dau vao PA tao thanh chu trinh
	for(; i < n*(n-1)/2; i++){
		r_dau = find_root(parent, list[i].dau);
		r_cuoi = find_root(parent, list[i].cuoi);
		if(!dinh_cap3(PA, n-1, list[i]) && !chu_trinh(r_dau, r_cuoi)){
			PA[n-1] = list[i];
			break;
		}
	}
}

int main(){
	Canh list[MAX];
	int n;
	printf("\t\t\t--- Bai toan duong di cua nguoi giao hang (TSP)---\n");
	read_file(list,&n);
	printf("Danh sach cac canh cua do thi\n");
	print_file(list, n*(n-1)/2, 0);
	bubbleSort(list, n*(n-1)/2);
	printf("\nDanh sach cac canh cua do thi da sap xep\n");
	print_file(list, n*(n-1)/2, 0);
	Canh PA[n];
	greedy(list, n, PA);
	printf("PHUONG AN\n");
	print_file(list, n, 1);	
	return 0;
}
