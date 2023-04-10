#include<stdio.h>
int main(){
	long int n,n1=1,i; //voi n1 == n!
	scanf("%ld",&n);
	for(i=2;i<=n;i++)
		n1=n1*i;
	printf("%ld! = %ld",n,n1);
	return 0;
}