#include<stdio.h>
int main(){
	int x,i,n,temp;
	temp=1;
	do{
		printf("Nhap vao lan luot x va n:\n");
		scanf("%d%d",&x,&n);
	}while(x<0 || n<0);
	for(i=1;i<=n;i++)
		temp=temp*x;
	printf("So can tinh la:%d",temp);
	return 0;
}