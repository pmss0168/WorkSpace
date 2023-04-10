#include<stdio.h>
int main (){
	int d,m,y;
	printf("Chuong trinh hien thi ngay thang nam sinh cua ban\n");
	scanf("%d%d%d",&d,&m,&y);
	printf("Ngay sinh cua ban la: %02d/%02d/%04d",d,m,y);
	return 0;
}