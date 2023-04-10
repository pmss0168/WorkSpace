#include<stdio.h>
int main (){
	int a[1000],b[1000];
	int n,i=0,j;
	printf("Nhap vao so phan tu trong mang:\n");
	scanf("%d",&n);
	
	while(i<=n-1){
		printf("a[%d]=",i);
		scanf("%d ",&a[i]);
		j=i+1;
		while(j<n)
			if(a[i]>a[j]){
				for(i=0;i<n;i++){
						printf("a[%d]=",i);
						scanf("%d ",&a[i]);
				}
			}
	}
	
	printf("Cac phan tu cua day A:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("Cac phan tu cua day B:\n");
	for(i=0;i<n;i++)
		printf("%d",b[i]);
	return 0;
}