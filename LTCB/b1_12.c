#include<stdio.h>
int main(){
	float r,r1,r2,r3;
	printf("--Chuong trinh tinh tong dien tro R--");
	scanf("%f%f%f",&r1,&r2,&r3);
	r=(1/r1)+(1/r2)+(1/r3);
	printf("Tong dien tro R la:%.3f",1/r);
	return 0;
}