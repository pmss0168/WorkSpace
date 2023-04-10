#include<stdio.h>
int main(){
	int n,tong,dem,i,tam;
	tong=0;dem=0;
	printf("Nhap n:");
	scanf("%d",&n);
	while(n>0){
		dem++;
		tam=n%10;
		tong=tong+tam;
		n=n/10;
	}
	printf("tong cua so la %d va co %d so",tong,dem);
	return 0;		
}