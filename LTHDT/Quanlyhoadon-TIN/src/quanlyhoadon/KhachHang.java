package quanlyhoadon;

import java.util.Scanner;

public class KhachHang {
	private String mso, hten, dchi;
	private boolean phai;
	private HoaDon dsHD[];
	public KhachHang() {
		mso = new String();
		hten = new String();
		dchi = new String();
		phai = true;
	}
	public KhachHang(KhachHang kh) {
		mso = new String(kh.mso);
		hten = new String(kh.hten);
		dchi = new String(kh.dchi);
		phai = kh.phai;
		for (int i = 0; i < kh.dsHD.length; ++i) {
			dsHD[i] = new HoaDon(kh.dsHD[i]);
		}
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so khach hang: ");
		mso = sc.nextLine();
		System.out.println("Nhap ho ten khach hang: ");
		hten = sc.nextLine();
		System.out.println("Nhap dia chi khach hang: ");
		dchi = sc.nextLine();
		System.out.println("Nhap so hoa don da mua: ");
		int n = sc.nextInt();
		for (int i = 0; i < n; ++i) {
			System.out.println("Nhap hoa don thu "+(i+1)+" : ");
			dsHD[i] = new HoaDon();
			dsHD[i].nhap();
		}
	}
	public void in() {
		System.out.println("Ma so khach hang: "+mso);
		System.out.println("Ho ten: "+hten);
		System.out.println("Dia chi khach hang: "+dchi);
		if (dsHD.length > 0) {
			for (int i = 0; i < dsHD.length; ++i) {
				System.out.println("Hoa don thu "+(i+1)+" : ");
				dsHD[i].in();
			}
		}
		
	}
	
}
