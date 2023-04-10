#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n<=20)
		printf("cuoc phai tra: %.2f",1.00*20000);
	else if(n>20 && n<=50)
			printf("cuoc phai tra: %.2f",1.00*(20000+(n-20)*2000));
		 else if(n>50)
		 		printf("cuoc phai tra: %.2f",1.00*(20000+30*2000+(n-50)*1000));
	return 0;
}