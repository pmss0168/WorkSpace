package BaiTap;

import java.util.Scanner;

public class GDich {
	private int mgd;
	private String hten, ngay;
	private boolean tthai;
	public GDich() {
		mgd = 0;
		hten = new String();
		ngay = new String();
		tthai = true;
	}
	public GDich(GDich gd) {
		mgd = gd.mgd;
		hten = new String(gd.hten);
		ngay = new String(gd.ngay);
		tthai = gd.tthai;
	}
	public int getMGD() {
		return mgd;
	}
	public String getYear() {
		ngay.trim();
		int p = ngay.lastIndexOf("-");
		return ngay.substring(p+1);
	}
	public String getMonth() {
		ngay.trim();
		int p = ngay.indexOf("-");
		int q = ngay.lastIndexOf("-");
		return ngay.substring(p+1, q);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma giao dich: ");
		mgd = sc.nextInt();
		sc.nextLine();
		System.out.println("Nhap ho ten nguoi giao dich: ");
		hten = sc.nextLine();
		System.out.println("Nhap ngay thang nam giao dich: ");
		ngay = sc.nextLine();
		System.out.println("Nhap trang thai giao dich: ");
		tthai = sc.nextBoolean();
	}
	public void in() {
		System.out.println("(" +mgd+ "; " +hten+ "; " +ngay+ "; " +tthai+ ")");
	}
	public String toString() {
		return "(" +mgd+ "; " +hten+ "; " +ngay+ "; " +tthai+ ")";
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		GDich gd1 = new GDich();
		gd1.nhap();
		gd1.in();
		GDich gd2 = new GDich(gd1);
		gd2.in();
		//test
//		System.out.println(gd1.getYear());
//		System.out.println(gd1.getMonth());
	}
}









