package QuanLyHoaDon;

import java.util.Scanner;

public class HangHoa {
	private String mso, ten;
	private int nsx;
	public HangHoa() {
		mso = new String();
		ten = new String();
		nsx = 1;
	}
	public HangHoa(String maso, String tenhh, int ngaysx) {
		mso = maso;
		ten = tenhh;
		nsx = ngaysx;
	}
	public HangHoa(HangHoa hh) {
		mso = new String(hh.mso);
		ten = new String(hh.ten);
		nsx = hh.nsx;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so:");
		mso = sc.nextLine();
		System.out.println("Nhap ten:");
		ten = sc.nextLine();
		System.out.println("Nhap ngay san xuat:");
		nsx = sc.nextInt();
	}
	public void in() {
		System.out.println("Ma so: " + mso);
		System.out.println("Ten: " + ten);
		System.out.println("Ngay san xuat: " + nsx);
	}
	public String toString() {
		return "(" +mso+ "; " +ten+ "; " +nsx+ ")";
	}
}
















