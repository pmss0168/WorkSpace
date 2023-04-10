#include<stdio.h>
#include<time.h>
int main(){
	int d,m,y;
 	struct tm ts;
    time_t now;
    int year;
    
    now = time(0);            // Lấy ngày giờ hiện tại
    ts = *localtime(&now);    // Chuyển sang ngày giờ địa phương
    year = ts.tm_year + 1900; // Tính năm hiện tại
	
	printf("Chuong trinh tinh tuoi hien tai cua ban\n");
	scanf("%d%d%d",&d,&m,&y);
	printf("Ban sinh ngay %02d thang %02d nam %04d, Nam nay, ban %d tuoi",d,m,y,year-y);
	return 0;
}