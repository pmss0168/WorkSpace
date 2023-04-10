//Pham Minh Sang, B2110976
package ThiThu1;

import java.util.Scanner;

public class CongNhan extends Nguoi{
	private String cty;
	private int nglam;
	public CongNhan() {
		super();
		cty = new String();
		nglam = 0;
	}
	public CongNhan(CongNhan c) {
		super(c);
		cty = new String(c.cty);
		nglam = c.nglam;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		super.nhap();
		System.out.println("Nhap ten cong ty:");
		cty = sc.nextLine();
		System.out.println("Nhap ngay lam: ");
		nglam = sc.nextInt();
	}
	public void in() {
		System.out.println("[" +super.toString()+ "; " +cty+ "; " +nglam+ "]");
	}
	public String toString() {
		return "[" +super.toString()+ "; " +cty+ "; " +nglam+ "]";
	}
	public long tienluong() {
		return nglam*200000;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, i = 0;
		System.out.println("Nhap so luong cong nhan:");
		n = sc.nextInt();
		sc.nextLine();
		CongNhan s[] = new CongNhan[n];
		for(CongNhan t: s) {
			System.out.println("Nhap cong nhan thu " +(i+1));
			s[i] = new CongNhan();
			s[i].nhap();
			i++;
		}
		for(CongNhan t: s) {
			t.in();
		}
		long tong = 0;
		for(CongNhan t: s) {
			tong += t.tienluong();
		}
		System.out.println("Tong tien luong:" +tong);
	}
}
