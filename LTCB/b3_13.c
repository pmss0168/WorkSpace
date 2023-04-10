#include<stdio.h>
#include<math.h>
int main(){
	float e,a,x0,x1,x,t;
	int i,n;
	printf("Nhap vao n va e: ");
	scanf("%d%f",&n,&e);
	x0=1.0*(1+n)/2;
	x1=(x0+1.0*(a/x0))/2;
	t=abs((x1-x0)/x0);
	while(t>=e){
		x0=x1;
		x1=(x0+(1.0*a)/x0)/2;
		a=x1;	
	}
	printf("Can bac hai cua so a la: %.2f",a);		
return 0;		
}