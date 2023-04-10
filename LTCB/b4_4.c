#include<stdio.h>
int hoanhao(int n){
	int i,s=0;
	for (i=1;i<=(n/2);i++){
		if(n%i==0) s=s+i;
	}
	return (s==n);
}
int main(){
	int a;
	scanf("%d",&a);
	if(hoanhao(a)) printf("La so hoan hao");
	else printf("Khong la so hoan hao");
	return 0;
}