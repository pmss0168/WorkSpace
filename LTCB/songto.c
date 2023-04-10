#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
int ngto(int n){
	int i;
	if(n<2) return 0;
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0) return 0;
	return 1;
}
int main(){
	int i,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(ngto(a[i]))
			printf("%d ",a[i]);
	}
	return 0;
}