package BaiTap;

import java.util.Scanner;

public class GDichTTe extends GDich{
	private float dgia;
	private int sluong;
	private char loai;
	private float tgia;
	public GDichTTe() {
		super();
		dgia = 0.0f;
		sluong = 0;
		loai = 0;
		tgia = 0.0f;
	}
	public GDichTTe(GDichTTe g) {
		super(g);
		dgia = g.dgia;
		sluong = g.sluong;
		loai = g.loai;
		tgia = g.tgia;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		super.nhap();
		System.out.println("Nhap don gia: ");
		dgia = sc.nextFloat();
		System.out.println("Nhap so luong: ");
		sluong = sc.nextInt();
		sc.nextLine();
		System.out.println("Nhap loai tien te: ");
		loai = sc.nextLine().charAt(0);
		System.out.println("Nhap ti gia: ");
		tgia = sc.nextFloat();
	}
	public void in() {
		//super.in();
		System.out.println("[" + super.toString()+ "; " +dgia+ "; " +sluong+ "; " +loai+ "; " +tgia+ "]");
	}
	public String toString() {
		return "[" +super.toString()+ "; " +dgia+ "; " +sluong+ "; " +loai+ "; " +tgia+ "]";
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong phan tu danh sach:");
		int n = sc.nextInt();
		sc.nextLine();
		GDichTTe ds[];
		ds = new GDichTTe[n];
		for(int i = 0; i< n; i++) {
			ds[i] = new GDichTTe();
			ds[i].nhap();
		}
		for(GDichTTe t : ds) {
			t.in();
		}
		//Hien thi tat ca ma giao dich tien te co gia tri tren 100K VND
		int i = 0;
		for(GDichTTe t: ds) {
			if(t == null)
				break;
			else {
				if(t.dgia > 100000) {
					System.out.println("Ma giao dich co gia tri tren 100000 VND thu " +(i+1)+ " : ");
					System.out.println(t.getMGD());
					i++;
				}
			}
		}
		//Thong ke so tien cac giao dich theo thang
		System.out.println("Nhap thang ban can thong ke: ");
		int thang = sc.nextInt();
		float tong = 0.0f;
		sc.nextLine();
		for(GDichTTe t: ds) {
			if(thang == Integer.parseInt(t.getMonth())) {
				tong += t.dgia;
			}
		}
		System.out.println("Tong tien cua thang " +thang+ " la: " +tong);
		//Thong ke so tien cac giao dich theo nam
		System.out.println("Nhap nam ban can thong ke: ");
		int nam =sc.nextInt();
		float tong1 = 0.0f;
		for(GDichTTe t: ds) {
			if(nam == Integer.valueOf(t.getYear())) {
				tong1 += t.dgia;
			}
		}
		System.out.println("Tong tien cua nam " +nam+ " la: " +tong1);
	}

}
