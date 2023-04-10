#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
int main(){
	long int n, rev=0;
	int du;
	scanf("%ld",&n);
	while(n%10==0){
		printf("0");
		n/=10;
	}
	while(n!=0){
		du=n%10;
		rev=rev*10+du;
		n/=10;
	}
	printf("%d",rev);
	return 0;
}