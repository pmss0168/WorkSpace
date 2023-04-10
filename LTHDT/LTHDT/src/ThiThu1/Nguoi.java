//Pham Minh Sang, B2110976
package ThiThu1;

import java.util.Scanner;

public class Nguoi {
	private String ten;
	private NgayThang ngsinh;
	public Nguoi() {
		ten = new String();
		ngsinh = new NgayThang();
	}
	public Nguoi(Nguoi n) {
		ten = new String(n.ten);
		ngsinh = new NgayThang(n.ngsinh);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ten: ");
		ten = sc.nextLine();
		System.out.println("Nhap ngay sinh:");
		ngsinh.nhap();
	}
	public void in() {
		System.out.println("(" +ten+ "; " +ngsinh+ ")");
	}
	public String toString() {
		return "(" +ten+ "; " +ngsinh+ ")";
	}
}
