#include<stdio.h>
int main(){
	float lt,th1,th2,th3,th4,diem;
	printf("Chuong trinh tinh diem dat mon LTCB\n");
	scanf("%f %f %f %f %f",&lt,&th1,&th2,&th3,&th4);
	diem=(lt+th1+th2+th3+th4)/5;
	if (diem >= 4){
		printf("Dat mon hoc");
	}else {
		printf("Khong dat mon hoc");
	}
	return 0;
}