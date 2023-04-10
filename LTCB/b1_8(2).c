#include<stdio.h>
int main () {
	int a,b,c,d,tong;
	printf("Chuong trinh tinh tong cac so cua mot so co ba chu so");
	printf("\nNhap vao mot so co ba chu so:");scanf("%d",&a);
	if(a>99 && a<1000){
		b=a/100;
		c=(a/10)%10;
		d=a%10;
		tong=b+c+d;
		printf("Ket qua la:%d",tong);
	}else{
	printf("Ban da nhap sai, hay khoi chay lai chuong trinh va nhap lai");
	}
return 0;
}