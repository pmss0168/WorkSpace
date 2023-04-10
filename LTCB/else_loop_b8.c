#include<stdio.h>
int main(){
	int n,i,t;
	scanf("%d",&n);
	printf("%d Times Table\n",n);
	printf("====================\n");
	for(i=1;i<=10;i++){
		t=n*i;
		printf("%d x %d = %d\n",n,i,t);
	}
	return 0;	
}