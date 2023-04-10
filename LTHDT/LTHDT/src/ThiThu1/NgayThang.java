//Pham Minh Sang, B2110976
package ThiThu1;

import java.util.Scanner;

public class NgayThang {
	private int ngay, thang, nam;
	public NgayThang() {
		ngay = thang = nam = 0;
	}
	public NgayThang(NgayThang n) {
		ngay = n.ngay;
		thang = n.thang;
		nam = n.nam;
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ngay:");
		ngay = sc.nextInt();
		System.out.println("Nhap thang:");
		thang = sc.nextInt();
		System.out.println("Nhap nam:");
		nam = sc.nextInt();
	}
	public void in() {
		System.out.println(ngay+ "/" +thang+"/" +nam);
	}
	public String toString() {
		return ngay+ "/" +thang+"/" +nam;
	}
}
