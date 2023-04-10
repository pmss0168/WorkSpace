#include<stdio.h>
int main(){
	int a[100];
	int i,tong=0,n;
	float tbc=1;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++){
		tong=tong+a[i];
	}
	tbc=1.0*tong/n;
	printf("Tong cua mang la: %d\n",tong);
	printf("TBC cua mang la: %.2f",tbc);
	return 0;
}