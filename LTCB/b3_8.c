#include<stdio.h>
int main(){
	int i;
	float s,temp;
	scanf("%f",&s);
	temp=1;
	for(i=2;temp<=s;i++){
		temp=temp+(1.0/i);
	}           
	printf("So n nho nhat la: %d",i-1);
}