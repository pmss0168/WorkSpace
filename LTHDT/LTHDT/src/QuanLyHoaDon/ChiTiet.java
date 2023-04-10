package QuanLyHoaDon;

import java.util.Scanner;

public class ChiTiet {
	private int sluong;
	private long dgia;
	private HangHoa hh;
	public ChiTiet() {
		sluong = 0;
		dgia = 0;
		hh = new HangHoa();
	}
	public ChiTiet(int soluong, long dongia, HangHoa h) {
		sluong = soluong;
		dgia = dongia;
		hh = new HangHoa(h);
	}
	public ChiTiet(ChiTiet ct) {
		sluong = ct.sluong;
		dgia = ct.dgia;
		hh = new HangHoa(ct.hh);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong:");
		sluong = sc.nextInt();
		System.out.println("Nhap don gia:");
		dgia = sc.nextLong();
		System.out.println("Nhap hang hoa:");
		hh.nhap();
	}
	public void in() {
		System.out.println("So luong: " + sluong);
		System.out.println("Don gia: " + dgia);
		System.out.println("Hang hoa: " + hh);
	}
	public long tinhtien() {
		return sluong*dgia;
	}
	public String toString() {
		return "(" +sluong+ "; " +dgia+ "; " +hh+ ")"; 
	}
}
