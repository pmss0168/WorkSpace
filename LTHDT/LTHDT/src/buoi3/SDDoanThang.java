package buoi3;

import buoi2.Diem;
public class SDDoanThang {
	public static void main(String[] args) {
		Diem A = new Diem(2,5);
		Diem B = new Diem(20,35);
		DoanThang AB;
		AB = new DoanThang(A,B);
		AB.tinhtien(5, 3);
		AB.in();
		DoanThang CD = new DoanThang();
		CD.nhap();
		CD.in();
		System.out.println("Khoang cach CD: " + CD.khoangcachDoanThang());
		System.out.println("Goc cua doan thang CD voi truc hoanh la: " + CD.gocDoanThang());
	}
}




















