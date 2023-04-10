#include<stdio.h>
int main(){
	int f,f1,f2,n,i;
	scanf("%d",&n);
	f1=0;f2=1;
	printf("\n%d %d",f1,f2);
	for(i=2;i<n;++i){
		f=f1+f2;
		printf(" %d",f);
		f1=f2;
		f2=f;
	}
return 0;
}