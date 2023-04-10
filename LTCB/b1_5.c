#include <stdio.h>
int main () {
	int tongsotinchi;
	float tongdiem,diemtrungbinh;
	printf("--Chuong trinh tinh diem trung binh hoc tap--");
	printf("\nNhap vao tong so tin chi:");scanf("%d",&tongsotinchi);
	printf("Nhap vao tong diem:");scanf("%f",&tongdiem);
	diemtrungbinh=tongdiem/tongsotinchi;
	printf("Ket qua diem trung binh hoc tap la:%f",diemtrungbinh);
	return 0;

}