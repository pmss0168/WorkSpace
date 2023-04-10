#include<stdio.h>
#include<math.h>
int main(){
	int s1,s2,n,i;
	scanf("%d",&n);
	s1=0;s2=0;
	for(i=1;i<=n;i++)
		s1=s1+i;
	for(i=1;i<=n;i++){
		s2=s2+pow(-1,i+1)*i;
	}
	printf("Tong s1: %d va s2: %d",s1,s2);
return 0;	
}