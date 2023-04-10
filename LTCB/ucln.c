#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,r;
    scanf("%d %d",&a,&b);
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    printf("%d",abs(a));
    return 0;
}