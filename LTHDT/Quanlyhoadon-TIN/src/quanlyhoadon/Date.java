package quanlyhoadon;

import java.util.Scanner;

public class Date {
	private int ng, th, nam;
	private HoaDon dsHD[];
	private KhachHangVIP dsVIP[];
	public Date() {
		ng = th = nam = 1;
	}
	public Date(Date date) {
		ng = date.ng;
		th = date.th;
		nam = date.nam;
		for (int i=0; i < date.dsHD.length; ++i) {
			dsHD[i] = new HoaDon(date.dsHD[i]);
		}
		for (int i=0; i < date.dsVIP.length; ++i) {
			dsVIP[i] = new KhachHangVIP(date.dsVIP[i]);
		}
	}
	public boolean hopLe() {
		int[] check = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if ((nam % 400 == 0)||((nam % 100 != 0)&&(nam % 4 ==0 ))) check[2] = 29;
		if((nam < 1) || ((th < 1)||(th > 12)) || ((check[th] < ng) || (1 > ng)) )
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
		System.out.println("So hoa don trong ngay: ");
		int n;
		n = sc.nextInt();
		dsHD = new HoaDon[n];
		for (int i = 0; i < n; ++i) {
			dsHD[i] = new HoaDon();
			System.out.println("Nhap hoa don thu "+(i+1)+" :");
			dsHD[i].nhap();
		}
		System.out.println("So khach hang VIP trong ngay:");
		n = sc.nextInt();
		dsVIP = new KhachHangVIP[n];
		for (int i = 0; i < n; ++i) {
			dsVIP[i] = new KhachHangVIP();
			System.out.println("Nhap hoa khach thu "+(i+1)+" :");
			dsVIP[i].nhap();
		}
	}
	public void in() {
		System.out.println(ng+"/"+th+"/"+nam);
		if(dsHD.length > 0)
			for (int i = 0; i < dsHD.length; ++i) {
				System.out.println("Hoa don thu "+(i+1)+" la:");
				dsHD[i].in();
			}
		if (dsVIP.length > 0)
			for (int i = 0; i < dsVIP.length; ++i) {
				System.out.println("Khach hang thu "+(i+1)+" la:");
				dsVIP[i].in();
			}
	}
}
