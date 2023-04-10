#include <stdio.h>
#include <stdlib.h>
int min(int a, int b){
    if (a>b) return a;
    return b;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n],r[n+10],l[n+10], s[n+10], B[n+10];
    int t=0;
    for ( int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    s[0]=a[0];
    for (int i=1; i<n; i++){
        s[i]=s[i-1]+a[i];
    }
    l[1]=a[1],r[n]=a[n];l[0]=0;
     for(int i=n;i>=1;i--)
           B[i]=B[i+1]+a[i];
     for(int i=2;i<=n;i++)
           l[i]=min(l[i-1],s[i]);
     for(int i=n-1;i>=1;i--)
           r[i]=min(r[i+1]+a[i],a[i]);
     for(int i=1;i<=n;i++)
     {
           if(r[i]>0&&B[i]+l[i-1]>0)
                  t++;
     }
    
    printf("%d",t);
    return 0;
}