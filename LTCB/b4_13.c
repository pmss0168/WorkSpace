#include<stdio.h>
int  dem(int n){
	if(n<10 && n>-10) return 1;
	return 1+dem(n/10);
}
int main (){
	int n;
	scanf("%d",&n);
	printf("%d",dem(n));
	return 0;
}