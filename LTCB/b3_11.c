#include<stdio.h>
int isprime(int n){
	int flag=1;
	if(n<2) return flag=0;
	int i=2;
	while(i<n){
		if(n%i==0){
			flag=0;
			break;
		}
		i++;
	}
	return flag;
}
int main(){
	int n;
	printf("Nhap n");
	scanf("%d",&n);
	int i=0,check;
	while(i<n){
		check=isprime(i);
		if(check==1) printf("%d \n",i);
		++i;
	}
	return 0;
}