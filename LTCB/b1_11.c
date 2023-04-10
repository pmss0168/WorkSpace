#include <stdio.h>
int main() {
	char ch;
	printf("Chuong trinh nhap vao mot ki tu chuyen sang so ma ASCII");
	printf("\nNhap vao mot ki tu:");scanf("%c",&ch);
	printf("%d\n",ch);
	printf("Ki tu tiep theo cua %c la %c",ch,ch+1);
	return 0;
}