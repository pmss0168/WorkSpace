package BaiTap;

import java.util.Scanner;

public class ChuyenXe {
	private int mso;
	private String tnlx, nden;
	private float dthu;
	private Xe x;
	public ChuyenXe() {
		mso = 0;
		tnlx = new String();
		nden = new String();
		dthu = 0.0f;
		x = new Xe();
	}
	public ChuyenXe(ChuyenXe cx) {
		mso = cx.mso;
		tnlx = new String(cx.tnlx);
		nden = new String(cx.nden);
		dthu = cx.dthu;
		x = new Xe(cx.x);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so chuyen xe: ");
		mso = sc.nextInt();
		sc.nextLine();
		System.out.println("Nhap ten nguoi lai xe: ");
		tnlx = sc.nextLine();
		System.out.println("Nhap noi den: ");
		nden = sc.nextLine();
		System.out.println("Nhap doanh thu: ");
		dthu = sc.nextFloat();
		System.out.println("Nhap xe: ");
		x.nhap();
	}
	public void in() {
		System.out.println("Ma so chuyen xe: " +mso);
		System.out.println("Ten nguoi lai xe: " +tnlx);
		System.out.println("Noi den: " +nden);
		System.out.println("Doanh thu: " +dthu);
		System.out.println("Xe: " + x);
	}
	public String toString() {
		return "(" +mso+ "; " +tnlx+ "; " +nden+ "; " +dthu+ "; " +x+ ")";
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong danh sach chuyen xe: ");
		int m = sc.nextInt();
		sc.nextLine();
		ChuyenXe ds1[] = new ChuyenXe[m];
		for(int i = 0; i < m; i++) {
			System.out.println("Nhap chuyen xe thu " +(i+1)+ " : ");
			ds1[i] = new ChuyenXe();
			ds1[i].nhap();
		}
		for(ChuyenXe t : ds1) {
			t.in();
		}
		//Chuyen xe bi huy
		for(ChuyenXe t : ds1) {
			if(t == null)
				break;
			else {
				if(t.x.getTT() == 'K' || t.dthu < 100.000) {
					System.out.println("Ma so chuyen xe bi huy: " +t.mso);
				}
			}
		}
		//Loi nhuan tung loai xe
		float tdthu = 0.0f;
		System.out.println("Nhap loai xe ban can tinh loi nhuan: ");
		String check = sc.nextLine();
		for(ChuyenXe t : ds1) {
			if(check.compareTo(t.x.getLoai()) == 0) {
				tdthu += t.dthu;
			}
		}
		System.out.println("Tong doanh loi nhuan cua loai xe " +check+ " la: " +tdthu);
	} 
}








