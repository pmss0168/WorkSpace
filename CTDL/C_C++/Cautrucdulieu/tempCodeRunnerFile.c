#include <stdio.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}
int main(){
    printf("Nhap 3 so a b c: ");
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("So lon nhat la %d.", max(a,max(b,c)));
    return 0;
}