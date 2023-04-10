#include<stdio.h>
int main(){
	int a[100];
	int i,j,max,n;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
		max=a[0];
	}
	for(i=1;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
	printf("Phan tu lon nhat trong mang la: %d",max);
return 0;
}