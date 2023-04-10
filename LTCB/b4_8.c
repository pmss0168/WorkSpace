#include<stdio.h>
int gt(int n){
	if (n==0) return 1;
	else return n*gt(n-1);
}
int gt2(int n){ //can xu li lai
	int i,chan=1,le=1;
	for(i=1;i<=n;i++){
		if(n%2==0) return chan=chan*i;
		if(n%2!=0) return le=le*i;
	}
} 
int snt(int n){
	int i;
	if(n<2) return 0;
	if(n=2) return 1; //neu hien thi 0 khong la so nguyen to
	for(i=3;i<=(n/2);i++){
		if(n%i==0) return 0;
	return 1; //neu hien thi 1 la so nguyen to
	}
}
int main(){
	int a;
	scanf("%d",&a);
	printf("n! bang:%d\n",gt(a));
	printf("n!! bang:%d\n",gt2(a));
	printf("Voi 0 khong la so nguyen to va 1 la so nguyen to\n");
	printf("%d",snt(a));
	return 0;
}