#include<stdio.h>
int main(){
	int a[100];
	int i,j,min,n;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
		min=a[0];
	}
	for(i=1;i<n;i++){
		if(min>a[i])
			min=a[i];
	}
	printf("Phan tu nho nhat trong mang la: %d",min);
return 0;
}