#include<stdio.h>
int main(){
	int a[100];
	int i,n,dem=0;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++){
		if(a[i]%2!=0){
			printf("So le dau tien trong mang la: %d\n",a[i]);
			break;
		}
	}
	for(i=0;i<n;i++){
		if(a[i]%2!=0) dem=dem+1;
	}
	printf("Tong so le trong mang la: %d",dem);
return 0;
}