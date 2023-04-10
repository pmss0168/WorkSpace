package buoi3;

import java.util.Scanner;

import buoi2.Diem;

public class DoanThang {
	private Diem d1, d2;
	public DoanThang(){
		d1 = new Diem();
		d2 = new Diem();
	}
	public DoanThang(Diem d11, Diem d22){
		d1 = new Diem(d11);
		d2 = new Diem(d22);
	}
	public DoanThang(int ax, int ay, int bx, int by){
		d1 = new Diem(ax, ay);
		d2 = new Diem(bx, by);
	}
	public DoanThang(DoanThang dt){
		d1 = new Diem(dt.d1);
		d2 = new Diem(dt.d2);
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap toa do diem thu nhat:");
		d1.nhapDiem();
		System.out.println("Nhap toa do diem thu hai:");
		d2.nhapDiem();
	}
	public void in(){
		System.out.println("[" + d1 + "," + d2 + "]");
	}
	public String toString(){
		return "[" + d1 + "," + d2 + "]";
	}
	public void tinhtien(int dx, int dy){
		d1.doiDiem(dx, dy);
		d2.doiDiem(dx, dy);
	}
	public float khoangcachDoanThang(){
		return d1.khoangCach(d2);
	}
	public double gocDoanThang(){
		return (double)Math.toDegrees(Math.atan2(d2.giaTriY() - d1.giaTriY(), d2.giaTriX() - d1.giaTriX()));
	}
}













