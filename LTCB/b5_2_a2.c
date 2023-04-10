#include<stdio.h>
#include<conio.h>
int main(){
	int a[100];
	int i, j, n, k, dem = 0;
	printf("nhap so phan tu cua mang:");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		printf("a[%d]=", i );
		scanf("%d", &a[i]);
	}
	printf("mang da nhap:\n");
	for(i=0;i<n;++i){
		printf(" %d ", a[i]);
	}
	// xoa phan tu trung
	for (i=0;i<n-1;i++){
    	j=i+1;
    	while (j<n)
    	if (a[i]==a[j]){
        	for (k=j;k<n-1;k++) 
				a[k]=a[k+1];
    	n=n-1;
    	}
    else j=j+1;
    }
    n--;
	printf("\nmang sau khi xoa la:\n");
	for (i = 0; i < n+1; i++) {
		printf(" %d ", a[i]);
	}
	return 0;
}