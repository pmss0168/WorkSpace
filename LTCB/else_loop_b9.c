#include<stdio.h>
int main(){
	int i,t,j;
	for(j=1;j<=9;j++){
	printf("%d Times Table\n",j);
	printf("====================\n");
	for(i=1;i<=10;i++){
		t=j*i;
		printf("%d x %d = %d\n",j,i,t);
	}
	printf("\n");
}
	return 0;	
}