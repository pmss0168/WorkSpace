#include<stdio.h>
int main(){
	float C,F;
	printf("--Chuong trinh doi do C thanh do F--\n");
	scanf("%f",&C);
	F=C*1.8+32;
	printf("Vay %.1f do C se bang %.1f do F",C,F);
	return 0;	
}