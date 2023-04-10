package buoi2;

import java.util.Scanner;

public class Diem {
	private int x,y;
	//Khoi tao gia tri ban dau cho thuoc tinh
	public Diem() {
		x=y=0;
	}
	public Diem(int x1, int y1) {
		x=x1;
		y=y1;
	}
	public Diem(Diem diem) {
		x = diem.x;
		y = diem.y;
	}
	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap toa do x: ");
		x=sc.nextInt();
		System.out.println("Nhap toa do y: ");
		y=sc.nextInt();
	}
	public void inDiem() {
		System.out.println("(" + x + "," + y +")");
	}
	public String toString() {
		return "(" + x + "," + y +")";
	}
	public void doiDiem(int dx, int dy) {
		x+=dx;
		y+=dy;
	}
	public int giaTriX() {
		return x;
	}
	public int giaTriY() {
		return y;
	}
	public float khoangCach() {
		return (float) Math.sqrt(x*x+y*y);
	}
	public float khoangCach(Diem d) {
		return (float) Math.sqrt(Math.pow(x-d.x,2)+Math.pow(y-d.y,2));
	}
	public Diem doiXung() {
		Diem d = new Diem(-x,-y);
		return d;
	}
}

























