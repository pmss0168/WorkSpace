package buoi1;

import java.util.Scanner;

public class bai7_tachten {
	public static String tachten(String hoten) {
		hoten.trim();
		int p = hoten.lastIndexOf(" ");
		return hoten.substring(p+1);
				
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String hoten=sc.nextLine();
		System.out.println(tachten(hoten));
	}
}
