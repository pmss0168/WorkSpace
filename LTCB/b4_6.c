#include<stdio.h>
float hoandoi(float *a,float *b){
	float t;
	t=*a;
	*a=*b;
	*b=t;
	return ;
}
int main(){
	float x,y;
	scanf("%f%f",&x,&y);
	hoandoi(&x,&y);
	printf("Gia tri sau khi doi la:%.2f %.2f",x,y);
	return 0;
}