#include<stdio.h>

int main(){
	int i,t,j;
	for(j=1;j<=3;j++){
		for(i=1;i<=10;i++){
			t=j*i;
			printf("%2d x %2d = %2d\n",j,i,t);
		}
		printf("\n");
	}
	printf("\n");
	for(j=4;j<=6;j++){
		for(i=1;i<=10;i++){
			t=j*i;
			printf("%2d x %2d = %2d\n",j,i,t);
		}
		printf("\n");
	}
	printf("\n");
	for(j=7;j<=9;j++){
		for(i=1;i<=10;i++){
			t=j*i;
			printf("%2d x %2d = %2d\n",j,i,t);
		}
		printf("\n");
	}
	return 0;	
}