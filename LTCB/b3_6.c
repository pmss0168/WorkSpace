#include<stdio.h>
#include<math.h>
int main(){
	int n,i,tam;
	scanf("%d",&n);
	tam=0;
	if (n<2) printf("Khong la so nguyen to");
	if (n==2) printf("La so nguyen to");
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		tam=1;
	}
	if(tam==0) printf("La so nguyen to");
	else printf("Khong la so nguyen to");
return 0;
}