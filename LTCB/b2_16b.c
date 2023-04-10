#include <stdio.h>
#include <math.h>
int main () {
	float a,b,c,x1,x2,delta;
	printf("--Chuong tinh phuong trinh bac hai--");
	printf("\n\nNhap vao phuong trinh a*x*x+b*x+c");
	printf("\nNhap vao so a:");scanf("%f",&a);
	printf("Nhap vao so b:");scanf("%f",&b);
	printf("Nhap vao so c:");scanf("%f",&c);
	delta=b*b-4*a*c;
	if (a==b==c==0) {
		printf("Phuong trinh da cho co vo so nghiem");
	}
	if ( delta < 0){
		printf ("Phuong trinh vo nghiem");
		return 0;
	}else if ( delta == 0){
		x1=x2=-b/(2*a);
		printf("Phuong trinh co nghiem kep x1=x2=%f",x1);
		return 1;
	}else {
		x1=(-b+sqrt(delta))/(2*a);
		x2-(-b-sqrt(delta))/(2*a);
		printf("Phuong trinh co hai nghiem x1=%f va x2=%f",x1,x2);
		return 3;
		}
		
	return 4;
}