package QuanLyHoaDon;

import java.util.Scanner;

public class Date {
	private int ng, th, nam;
	public Date() {
		ng = th = nam = 1;
	}
	public Date(int ngay, int thang, int nam1) {
		ng = ngay;
		th = thang;
		nam = nam1;
	}
	public Date(Date date) {
		ng = date.ng;
		th = date.th;
		nam = date.nam;
	}
	public boolean hopLe() {
		int[] check = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if ((nam % 400 == 0)||((nam % 100 != 0)&&(nam % 4 ==0 ))) check[2] = 29;
		if((nam < 1) || ((th < 1)||(th > 12)) || ((ng > check[th]) || (ng < 1)) )
			return false;
		return true;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("Moi ban nhap ngay: ");
			ng = sc.nextInt();
			System.out.println("Moi ban nhap thang: ");
			th = sc.nextInt();
			System.out.println("Moi ban nhap nam: ");
			nam = sc.nextInt();
		}while(!hopLe());
	}
	public void in() {
		System.out.println(ng+"/"+th+"/"+nam);
	}
	public String toString() {
		return ng+"/"+th+"/"+nam;
	}
}
