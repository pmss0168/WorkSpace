#include<stdio.h>
#include<math.h>
int main(){
	int k,i;
	float pi,eps;
	do {
	scanf("%d%f",&k,&eps);
	}while (eps>=0.01 || eps<=0.00);
	for(i=1;i<=k;i++){
		pi=4*(1+(pow(-1,k)*(1/(1.0*(2*k)+1))));
		while (4/(2*i+1)>eps) break;		
	}
	printf("So pi bang: %.2f",pi);
	return 0;
}