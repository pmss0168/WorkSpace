#include<stdio.h>
int main(){
	int a[100];
	int i,n,j,t;
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
	}
	printf("Day so khi chua sap xep la:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	printf("\nDay so sau khi sap xep la: \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
return 0;
}