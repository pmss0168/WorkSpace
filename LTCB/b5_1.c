#include<stdio.h>	
int main(){
	int n,i,t;
	int arr[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		n=n/2;
		arr[i]=n%2;
	}
	for(i=n-1;i>=0;i--)
		printf("%d",arr[i]);
	return 0;
}