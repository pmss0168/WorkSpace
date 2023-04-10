#include<stdio.h>
int main () {
	int number;
	printf("Chuong trinh thong bao tinh chan le\n");
	scanf("%d",&number);
	if(number%2 == 0){
		printf("%d la so chan",number);
	}else {
		printf("%d la so le",number);
	}
	return 0;
}