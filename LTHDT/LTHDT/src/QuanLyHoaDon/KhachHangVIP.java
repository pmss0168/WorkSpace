package QuanLyHoaDon;

import java.util.Scanner;

public class KhachHangVIP extends KhachHang {
	private float kgiam;
	public KhachHangVIP() {
		super();
		kgiam = 0.0f;
	}
	public KhachHangVIP(KhachHang kh, float khuyenmai) {
		super(kh);
		kgiam = khuyenmai;
	}
	public KhachHangVIP(KhachHangVIP vip) {
		super((KhachHang) vip);
		kgiam = vip.kgiam;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		super.nhap();
		System.out.println("Nhap khuyen mai giam:");
		kgiam = sc.nextFloat();
	}
	public void in() {
		super.in();
		System.out.println("Khuyen mai giam: " + kgiam);
	}
	public String toString() {
		return super.toString() + "Kuyen mai giam: " + kgiam;
	}
	public float getKGiam() {
		return kgiam;
	}
}
