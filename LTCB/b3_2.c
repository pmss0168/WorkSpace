#include<stdio.h>
int main(){
	int n,i,temp;
	printf("Nhap vao luy thua can tinh\n");
	scanf("%d",&n);
	temp=1;
	for(i=1;i<=n;i++)
		temp=temp*i;
	printf("Luy thua cua %d la: %d",n,temp);
	return 0;
}