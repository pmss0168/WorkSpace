#include<stdio.h>
int main(){
	char mau;
	printf("Chuong trinh doi ky tu thanh mau sac");
	printf("Nhap ma mau: ");scanf("%c",&mau);
	switch(mau){
		case 'r': 
		case 'R': printf("RED\n");break;
		case 'g': 
		case 'G': printf("GREEN\n");break;
		case 'b': 
		case 'B': printf("BLUE\n");break;
		default	: printf("BLACK\n");
	}
	return 0;
}