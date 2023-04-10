package BaiTap;

import java.util.Scanner;

public class NhanVien {
	private String msnv, hten, cvu;
	private int tnien;
	public NhanVien() {
		msnv = new String();
		hten = new String();
		cvu = new String();
		tnien = 0;
	}
	public NhanVien(String ms, String ht, String cv, int tn) {
		msnv = new String(ms);
		hten = new String(ht);
		cvu = new String(cv);
		tnien = tn;
	}
	public NhanVien(NhanVien nv) {
		msnv = new String(nv.msnv);
		hten = new String(nv.hten);
		cvu = new String(nv.cvu);
		tnien = nv.tnien;
	}
	public String getMS() {
		return msnv;
	}
	public String getHT() {
		return hten;
	}
	public String getCV() {
		return cvu;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so nhan vien: ");
		msnv = sc.nextLine();
		System.out.println("Nhap ho ten nhan vien: ");
		hten = sc.nextLine();
		System.out.println("Nhap chuc vu nhan vien: ");
		cvu = sc.nextLine();
		System.out.println("Nhap tham nien cong tac: ");
		tnien = sc.nextInt();
	}
	public void hthi() {
		System.out.println("(" +msnv+ "; " +hten+ "; " +cvu+ "; " +tnien+ ")");
	}
	public String toString() {
		return "(" +msnv+ "; " +hten+ "; " +cvu+ "; " +tnien+ ")";
	}
	public static void main(String[] args) {
		NhanVien nv1 = new NhanVien();
		nv1.nhap();
		nv1.hthi();
		NhanVien nv2 = new NhanVien("12345","Tran Tue Chau","",30);
		nv2.hthi();
	}
}
