#include<stdio.h>
#define s 1000
int main (){
	int n,i,j,k;
	int a[s];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<n-1;i++){
		for (j=i+1;j<n;j++)
			if (a[i]==a[j]){
				for (k=j;k<n-1;k++){
					a[k]=a[k+1];
					
				}
			n=n-1;
			}else j=j+1;
	}
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}