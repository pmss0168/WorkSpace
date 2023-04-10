#include<stdio.h>
int main(){
	float so1,so2;
	char pt;
	printf("Chuong trinh in ket qua phep tinh\n");
	scanf("%f %c %f",&so1,&pt,&so2);
	switch(pt){
		case '+': printf("%.2f",so1+so2);break;
		case '-': printf("%.2f",so1-so2);break;
		case '*': printf("%.2f",so1*so2);break;
		case '/': if(so2 == 0){
			printf("Khong the thuc hien phep tinh");
		}else{
			printf("%.2f",so1/so2);break;
			}
		default :printf("Khong ton tai phep tinh ban vua nhap");
}
	return 0;
}