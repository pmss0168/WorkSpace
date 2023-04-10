#include<stdio.h>
int main(){
	int a[100];
	int i,n,pos,val;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("Mang ban dau la:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nNhap vi tri can chen vao mang:\n");
	scanf("%d",&pos);
	printf("Nhap gia tri cua phan tu can chen:\n");
	scanf("%d",&val);
	for(i=n-1;i>=pos-1;i--)
		a[i+1]=a[i];
		a[pos-1]=val;
		printf("Mang sau khi chen la:\n");
	for(i=0;i<=n;i++)
		printf("%d ",a[i]);
return 0;
}