package BaiTap;

import java.util.Scanner;

public class CongTac {
	private NhanVien nvien;
	private String dvi;
	private int tnien;
	private boolean bche;
	public CongTac() {
		nvien = new NhanVien();
		dvi = new String();
		tnien = 0;
		bche = false;
	}
	public CongTac(CongTac ct) {
		nvien = new NhanVien(ct.nvien);
		dvi = new String(ct.dvi);
		tnien = ct.tnien;
		bche = ct.bche;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap thong tin nhan vien: ");
		nvien.nhap();
		System.out.println("Nhap don vi cong tac: ");
		dvi = sc.nextLine();
		System.out.println("Nhap tham nien cong tac: ");
		tnien = sc.nextInt();
		System.out.println("Nhap bien che true(co bien che), false(khong bienn che): ");
		bche = sc.nextBoolean();
	}
	public void hthi() {
		System.out.println("[" +nvien+ "; " +dvi+ "; " +tnien+ "; " +bche+ "]");
	}
	public String toString() {
		return "[" +nvien+ "; " +dvi+ "; " +tnien+ "; " +bche+ "]";
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong phan tu danh sach:");
		int m = sc.nextInt();
		sc.nextLine();
		CongTac ds[] = new CongTac[m];
		for(int i = 0; i< m ;i++) {
			ds[i] = new CongTac();
			System.out.println("Nhap danh sach thu " +(i+1)+ ": ");
			ds[i].nhap();
		}
		for(CongTac t :ds)
			t.hthi();
	
		//Hien thi ho ten nhan vien co ma so "12346"
		for(CongTac t: ds) {
			if(t.nvien.getMS().compareTo("12346") == 0) {
				System.out.println("NHo ten nhan vien can tim la: " +t.nvien.getHT());
			}	
		}
		//Liet ke nhan vien trong bien che theo chuc vu
		System.out.println("Nhap chuc vu can liet ke:");
		String check = sc.nextLine();
		int cnt = 0;
		for(CongTac t: ds) {
			if(t.nvien.getCV().compareTo(check) == 0) {
				if(t.bche == true) {
					cnt++;
				}
			}
		}
		System.out.println("So nhan vien trong bien che theo chuc vu la: " +cnt);
	}
}
