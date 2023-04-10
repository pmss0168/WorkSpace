package quanlyhoadon;

import java.util.Scanner;

public class ChiTiet {
	private int sluong;
	private long dgia;
	private HangHoa hh;
	public ChiTiet() {
		sluong = 0;
		dgia = 0;
	}
	public ChiTiet(ChiTiet ct) {
		sluong = ct.sluong;
		dgia = ct.dgia;
		hh = ct.hh;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap hang hoa: ");
		hh.nhap();
		System.out.println("Nhap so luong: ");
		sluong = sc.nextInt();
		System.out.println("Nhap don gia: ");
		dgia = sc.nextLong();
	}
	public void in() {
		hh.in();
		System.out.println("So luong: "+sluong);
		System.out.println("Don gia: "+dgia);
	}
}
