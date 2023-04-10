#include<stdio.h>
int main(){
	int tieuthu;
	printf("Chuong trinh tinh tien dien da su dung\n");
	printf("Nhap so dien ma ban da tieu thu\n");
	scanf("%d",&tieuthu);
	if(tieuthu<=100){
		printf("So tien phai tra la: %d",tieuthu*1200);
	}else{
		if(tieuthu>100 && tieuthu<=150){
			printf("So tien phai tra la: %d",100*1200-(tieuthu-100)*1300);
		}else{
			if(tieuthu>150 && tieuthu<=200){
				printf("So tien phai tra la: %d",100*1200-150*1300-(tieuthu-150)*1500);
			}else printf("So tien dien phai tra la: %d",100*1200-150*1300-200*1500-(tieuthu-200)*2000);
		}
	}		
	return 0;
}