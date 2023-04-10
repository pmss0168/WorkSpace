package quanlyhoadon;

import java.util.Scanner;

public class HangHoa {
	private String mso, ten;
	private int nsx;
	private HoaDon dsHD[];
	private ChiTiet chitiet;
	public HangHoa() {
		mso = new String();
		ten = new String();
		nsx = 1;
	}
	public HangHoa(HangHoa hh) {
		mso = new String(hh.mso);
		ten = new String(hh.ten);
		nsx = hh.nsx;
		if (hh.dsHD.length > 0) {
			for (int i = 0; i < hh.dsHD.length; ++i) {
				dsHD[i] = new HoaDon(hh.dsHD[i]);
			}
		}
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so hang hoa:");
		mso = sc.nextLine();
		System.out.println("Nhap ten hang hoa:");
		ten = sc.nextLine();
		System.out.println("Nhap ngay san xuat:");
		nsx = sc.nextInt();
		System.out.println("Nhap so luong hoa don:");
		int n = sc.nextInt();
		dsHD = new HoaDon[n];
		for (int i = 0; i < n; ++i) {
			System.out.println("Nhap hoa don thu "+(i+1)+" :");
			dsHD[i] = new HoaDon();
			dsHD[i].nhap();
		}
	}
	public void in() {
		System.out.println("Ma so hang hoa: "+mso);
		System.out.println("Ten hang hoa: "+ten);
		System.out.println("Ngay san xuat: "+nsx);
		System.out.println("So luong hoa don: ");
		for (int i = 0; i < dsHD.length; ++i) {
			System.out.println("Hoa don thu "+(i+1)+" :");
			dsHD[i].in();;
		}
	}
}
