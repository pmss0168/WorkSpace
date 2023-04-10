#include<stdio.h>
int gt(int n){
	if (n==0) return 1;
	else return n*gt(n-1);
}
int th(int n, int k){
	int t=1;
	t=gt(n)/(gt(k)*gt(n-k));
	return t;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);	//a=n  va b=k
	printf("%d",th(a,b));
	return 0;
}