#include <stdio.h>
#include <math.h>
int main () {
	float a,b,c,x;
	printf("--Chuong tinh phuong trinh bac nhat--");
	printf("\n\nNhap vao phuong trinh a*x+b=0");
	printf("\nNhap vao so a:");scanf("%f",&a);
	printf("Nhap vao so b:");scanf("%f",&b);
	if (a==0)
		if (b==0) printf("Phuong trinh vo so nghiem");
			else printf("Phuong trinh vo nghiem");
		else {
			x=-b/a;
			printf("Phuong trinh co nghiem la:%f",x);
		}	
	return 0;
}