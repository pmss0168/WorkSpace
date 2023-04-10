//Pham Minh Sang, B2110976
package ThiThu1;

import java.util.Scanner;

public class SinhVien extends Nguoi{
	private String lop;
	private float toan, ly, hoa;
	public SinhVien() {
		super();
		lop = new String();
		toan = ly = hoa = 0.0f;
	}
	public SinhVien(SinhVien s) {
		super(s);
		lop = new String(s.lop);
		toan = s.toan;
		ly = s.ly;
		hoa = s.hoa;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		super.nhap();
		System.out.println("Nhap ten lop:");
		lop = sc.nextLine();
		System.out.println("Nhap diem toan:");
		toan = sc.nextFloat();
		System.out.println("Nhap diem ly:");
		ly = sc.nextFloat();
		System.out.println("Nhap diem hoa:");
		hoa = sc.nextFloat();
	}
	public void in() {
		System.out.println("[" +super.toString()+ "; " +lop+ "; " +toan+ "; " + ly+ "; " +hoa+ "]");
	}
	public String toString() {
		return "[" +super.toString()+ "; " +lop+ "; " +toan+ "; " + ly+ "; " +hoa+ "]";
	}
	public Float dtb() {
		return (toan+ly+hoa)/3;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, i = 0;
		System.out.println("Nhap so luong sinh vien:");
		n = sc.nextInt();
		sc.nextLine();
		SinhVien s[] = new SinhVien[n];
		for(SinhVien t: s) {
			System.out.println("Nhap sinh vien thu " +(i+1));
			s[i] = new SinhVien();
			s[i].nhap();
			i++;
		}
		for(SinhVien t: s) {
			t.in();
		}
		i = 0;
		for(SinhVien t: s) {
			System.out.println("Diem trung binh cua sinh vien thu " +(i+1));
			System.out.println(t.dtb());
			i++;
		}
		System.out.println("Sinh vien co it nhat 2 diem mon hoc lon hon 8 va diem mon con lai khong nho hon 5:");
		for(SinhVien t: s) {
			if((t.toan>8 && t.ly>8 && t.hoa>=5) || (t.toan>8 && t.ly>=5 && t.hoa>8) || (t.toan>=5 && t.ly>8 && t.hoa>8))
					t.in();
		}
		
	}
}
