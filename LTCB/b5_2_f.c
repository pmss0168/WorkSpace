#include<stdio.h>
int main(){
	int a[100];
	int i,n,dem=0,dem1=0;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++){
		if(n==2) dem1=1;
		if(a[i]%2!=0){
			dem=dem+1;
		}
	}
	printf("Tong so nguyen to trong mang la: %d\n",dem+dem1);
	printf("Cac so nguyen to trong mang la:\n");
	for(i=0;i<n;i++){
		if(a[i]==2) printf("%d ",a[i]);
		if(a[i]%2!=0 && a[i]!=1) printf("%d ",a[i]);
	}
return 0;
}