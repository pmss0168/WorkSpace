#include <stdio.h>
int main() {
	int a,b,add,subt,mult,div1,div2; 
	printf("Chuong trinh tinh tong, hieu, nhan, chia ");
	printf("\nNhap vao so a:");scanf("%d",&a);
	printf("Nhap vao so b:");scanf("%d",&b);
	add=a+b;
	subt=a-b;
	mult=a*b;
	div1=a/b;						//chia lay phan nguyen
	div2=a%b;						//chia lay phan du
	printf("Tong cua hai so la:%d",add);
	printf("\nHieu cua hai so la:%d",subt);
	printf("\nBoi cua hai so la:%d",mult);
	printf("\nThuong(phannguyen) cua hai so la:%d",div1);
	printf("\nThuong(phandu) cua hai so la:%d",div2);
	return 0;
}