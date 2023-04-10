#include<stdio.h>
int main(){
	int a,b,c,max;
	printf("nhap vao 3 so a,b,c:\n");
	scanf("%d%d%d",&a,&b,&c);
	max = a;
	if (max<b)
		max = b;
	else if(max<c)
			max = c;
	printf("So lon nhat la: %d",max);
	return 0;
}