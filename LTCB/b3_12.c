#include<stdio.h>
int main(){
	int n,j,i;
	char A;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		for(j=0;j<=i;j++)
			printf("%c ",'A'+i);
		printf("\n");
	}
	return 0;		
}