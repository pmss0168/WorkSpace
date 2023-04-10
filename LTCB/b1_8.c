#include<stdio.h>
int main () {
	int a,b,c,d,tong;
	printf("Chuong trinh tinh tong cac so cua mot so co ba chu so");
	printf("\nNhap vao mot so co ba chu so:");scanf("%d",&a);
	b=a/100;
	c=(a-(b*100))/10;
	d=(a-(b*100)-(c*10));
	tong=b+c+d;
	printf("Ket qua la:%d",tong);
	return 0;
}