#include<stdio.h>
int rev(int n){
	int dao=0,t;
	if(n==0) return 0;
	else
		while (n>0){
		t=n%10;
		dao=dao*10+t;
		n=n/10;
		}
	return dao;
}
int main() {
	int n;
	scanf("%d",&n);
	printf("%d",rev(n));
	return 0;
}