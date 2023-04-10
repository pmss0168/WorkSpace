#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	float a,b;
	printf("Chuong trinh tinh tri tuyet doi\n");
	scanf("%f",&b);
	a=fabs(b);
	printf("Tri tuyet doi cua so vua nhap la:%.4f",a);
	return 0;
}