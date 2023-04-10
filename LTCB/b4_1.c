#include<stdio.h>
#include<math.h>
int gt(int n){
	if(n==0) return 1;
	else return n*gt(n-1);
}
float lt(float x, int n){
	float t=1;int i;
	for(i=1;i<=n;i++)
	t=t*x;
	return t;
}
int main(){
	int b,j;
	float a;
	float s1,s2,s3;
	scanf("%f%d",&a,&b);
	s1=1;s2=1;s3=1;
	for(j=1;j<=b;j++){
		s1=s1+lt(a,j);
		s2=s2+lt(-1,j)*lt(a,j);
		s3=s3+lt(a,j)/gt(j);
	}
	printf("%.2f %.2f %.2f",s1,s2,s3);
return 0;
}