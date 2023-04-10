#include<stdio.h>
int main(){
	int date,person,money;
	printf("Chuong trinh tinh tien thue sach\n");
	printf("Sinh vien nhap 1, khac nhap 2\n");
	scanf("%d",&person);
	printf("Nhap so ngay thue sach\n");
	scanf("%d",&date);
	if(person==1){
		if (date<=7 && date>0){
		money=2000;
		printf("So tien thue la %d dong",money);
		}else{
			money=2000+((date-7)*500);
			printf("So tien thue la %d dong",money);
		}
		}else{
			if (date<=7 && date>0){
				money=3000;
				printf("So tien thue la %d dong",money);
			}else{
				money=3000+((date-7)*700);
				printf("So tien thue la %d dong",money);
			}
		}	
	
return 0;
}