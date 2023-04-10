package quanlyhoadon;

import java.util.Scanner;

public class KhachHangVIP extends KhachHang{
	private float kgiam;
	public KhachHangVIP() {
		super();
		kgiam = (float) 0.0;
		
	}
	public KhachHangVIP(KhachHangVIP khVIP) {
		super((KhachHang)khVIP);
		kgiam = khVIP.kgiam;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		super.nhap();
		kgiam = sc.nextFloat();
	}
	public void in() {
		super.in();
		System.out.println("Khuyen mai giam: "+kgiam);
	}
}
