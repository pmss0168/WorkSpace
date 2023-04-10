package buoi2;

import java.util.Scanner;

public class Date {
	private int d,m,y;
	public Date() {
		d=m=y=1;
	}
	public Date(int d1, int m1, int y1) {
		d=d1;
		m=m1;
		y=y1;
	}
	public Date(Date day) {
		d = day.d;
		m = day.m;
		y = day.y;
	}
	public String toString() {
		return d + "/" + m + "/" + y;
	}
	public void hienThi() {
		System.out.println(d+"/"+m+"/"+y);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		do {
		System.out.println("Nhap ngay: ");
		d=sc.nextInt();
		System.out.println("Nhap thang: ");
		m=sc.nextInt();
		System.out.println("Nhap nam: ");
		y=sc.nextInt();
		}while(!hopLe());
	}
	public boolean hopLe() {
		int max[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		if((y%4 == 0 && y%100!=0) || (y%400==0))
			max[2]=29;
		if(y>0 && m>0 && m<13 && d>0 && d<=max[m])
			return true;
		return false;
	}
	public Date ngayHomSau() {
		Date day = new Date(d,m,y);
		day.d+=1;
		if(!day.hopLe()) { //Cong them mot thang neu vuot qua so ngay trong thang
			day.d=1;
			day.m++;
			if(!hopLe()) { //Cong them mot nam neu vuot qua so thang trong nam
				day.m=1;
				day.y++;
			}
		}
		return day;
	}
	public Date congNgay(int n) {
		Date day = new Date(d,m,y);
		for(int i=0; i<n; i++) {
			day=day.ngayHomSau();
		}
		return day;
	}
}
