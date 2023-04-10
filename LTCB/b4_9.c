#include<stdio.h>
float lt(float x, int n){
	float tam=1;
	int i;
	for(i=1;i<=n;i++){
		tam=tam*x;	
	} 
	return tam;
}
int main(){
	int a;
	float b;
	scanf("%f%d",&b,&a); 	//Voi a=n va b=x
	printf("Vay x mu n co gia tri la: %.2f",lt(b,a));
	return 0;
}