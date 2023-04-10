#include<stdio.h>
int main(){
	int so,a,b,c,d;
	float nut;
	do{
		printf("Nhap vao so co 4 chu so\n");
		scanf("%d",&so);
	} while(so<=1000 && so>=9999);
	a=so/1000;
	b=(so-(a*100))/10;
	c=(so-(a*100)-(b*10));
	d=so%10;
	nut=(a+b+c+d)%10;
	printf("So nut cua xe la:%.1f",nut);
return 0;
}