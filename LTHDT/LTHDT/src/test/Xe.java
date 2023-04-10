package test;

import java.util.Scanner;

public class Xe {
	private String soxe,loai,ngay;
	private char tthai; //(C/K);
	public Xe() {
		soxe = new String();
		loai = new String();
		ngay = new String();
		tthai = 'K';
	}
	public Xe(String sx, String l, String n, char t) {
		soxe = new String(sx);
		loai = new String(l);
		ngay = new String(n);
		tthai = t;
	}
	public Xe(Xe x) {
		soxe = new String(x.soxe);
		loai = new String(x.loai);
		ngay = new String(x.ngay);
		tthai = x.tthai;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so xe: ");
		soxe = sc.nextLine();
		System.out.println("Nhap loai xe: ");
		loai = sc.nextLine();
		System.out.println("Nhap ngay thang nam dang ky: ");	//ngay-thang-nam
		ngay = sc.nextLine();
		System.out.println("Nhap trang thai cho phep luu hanh: ");	//C/K
		tthai = sc.nextLine().charAt(0);
	}
	public void in() {
		System.out.println("So xe: " + soxe);
		System.out.println("Loai xe: " + loai);
		System.out.println("Ngay thang nam dang ky: " + ngay);
		System.out.println("Trang thai cho phep luu hanh: " + tthai);
	}
	public String toString() {
		return "(" +soxe+ "; " +loai+ "; " +ngay+ "; " +tthai+ ")"; 
	}
	public char getTT() {
		return tthai;
	}
	public String getLoai() {
		return loai;
	}
	public static void main(String[] args) {
		Xe x1 = new Xe();
		x1.nhap();
		x1.in();
		Xe x2 = new Xe(x1);
		x2.in();
	}
	
}












