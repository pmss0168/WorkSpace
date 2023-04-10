package BaiTap;

import java.util.Scanner;

public class CNguoi {
	private String id, hten, ngay;
	private char phai;	//Male (M), Female	(F);
	public CNguoi() {
		id = new String();
		hten = new String();
		ngay = new String();
		phai = 0;
	}
	public CNguoi(CNguoi cn) {
		id = new String(cn.id);
		hten = new String(cn.id);
		ngay = new String(cn.ngay);
		phai = cn.phai;
	}
	public String getHten() {
		return hten;
	}
	public String getYear() {
		ngay.trim();
		int p = ngay.lastIndexOf("-");
		return ngay.substring(p+1);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so passport hay cmnd: ");
		id = sc.nextLine();
		System.out.println("Nhap ho va ten: ");
		hten = sc.nextLine();
		System.out.println("Nhap ngay thang nam sinh: ");
		ngay = sc.nextLine();
		System.out.println("Nhap phai Nam (M), Nu (F): ");
		phai = sc.nextLine().charAt(0);
	}
	public void in() {
		System.out.println("Passport/CMND: " +id);
		System.out.println("Ho va ten: " +hten);
		System.out.println("Ngay thang nam sinh: " +ngay);
		if(phai == 'M') {
			System.out.println("Phai: Nam");
		}
		else
			System.out.println("Phai: Nu");
		
	}
	public String toString() {
		String s = "(" +id+ "; " +hten+ "; " +ngay;
		if(phai == 'M')
			s += "; Nam)"; 
		else
			s += "; Nu)";
		return s;
	}
	public static void main(String[] args) {
		CNguoi c1 = new CNguoi();
		c1.nhap();
		c1.in();
		CNguoi c2 = new CNguoi(c1);
		//c2.in();
		System.out.println(c2);
	}
}









