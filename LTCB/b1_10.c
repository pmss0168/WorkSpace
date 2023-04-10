#include<stdio.h>
int main () {
	int a,b,c,d,dao;
	printf("Chuong trinh tinh tong cac so cua mot so co ba chu so");
	printf("\nNhap vao mot so co ba chu so:");scanf("%d",&a);
	b=a/100;
	c=(a-(b*100))/10;
	d=(a-(b*100)-(c*10));
	dao=d*100+c*10+b;
	printf("So %d co so dao nguoc la:%d",a,dao);
	return 0;
}