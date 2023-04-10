#include<stdio.h>
int UCLN(int a, int b){
	if (a%b==0) return b;
	else return UCLN(b%a,a);
}
int main () {
	int m,n,t;
	scanf("%d%d",&m,&n);
	t=UCLN(m,n);
	m=m/t;
	n=n/t;
 	if (n!=1){
        if (n<0){
            m=m*-1;
            n=n*-1;
        }
        printf("rut gon: %d/%d",m,n);
    }
    else
        printf("rut gon: %d",m);
	return 0;
}