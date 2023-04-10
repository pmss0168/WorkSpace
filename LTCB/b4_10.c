#include<stdio.h>
long int gt(int n){
	if (n==0) return 1;
	else return n*gt(n-1);
}
long int th(int n, int k){
	int t=1;
	t=gt(n)/(gt(k)*gt(n-k));
	return t;
}
int main(){
	int a,i,j;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		for(j=0;j<=i;j++)
			printf("%ld ",th(i,j));		
		printf("\n");
	}
	return 0;
}