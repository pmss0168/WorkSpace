#include <stdio.h>
#include <hashtable.h>
#include <stdlib.h>
int maxkey(int A[], int N){
    int max=0;
    for(int i=0; i<N; i++){
        max<A[i] ? max=A[i]:max=max;
    }
    return max;
}
int* Hashtable(int A[], int N, int MAX){
    int *Hashtable_chacter;
    Hashtable_chacter = (int*)calloc(MAX,sizeof(int));
    for (int i=0; i<N; i++){
        *(Hashtable_chacter+A[i]) = i;
    }       
    return Hashtable_chacter;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int target;
    scanf("%d",&target);
    int *table;
    table=Hashtable(a,n,maxkey(a,n));
    for (int i=0; i<n; i++){
        if (table[(target-a[i])]>0) {
            printf("[%d,%d]",i,table[(target-a[i])]);
            break;
        }
    
    }
    return 0;
}