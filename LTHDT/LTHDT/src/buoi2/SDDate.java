package buoi2;

import java.util.Scanner;

public class SDDate {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Date A = new Date(9,11,2003);
		System.out.println("Ngay thang nam cua A la:");
		A.hienThi();
		Date B = new Date();
		System.out.println("Nhap ngay thang nam cua B:");
		B.nhap();
		System.out.println("Ngay thang nam cua B la:");
		B.hienThi();
		System.out.println("Ngay hom sau cua B la:");
		Date temp = new Date();
		temp = B.ngayHomSau();
		temp.hienThi();
		System.out.println("Nhap so ngay can cong");
		int n = sc.nextInt();
		System.out.println("Ngay thang nam cua A sau khi cong " + n + " ngay la:");
		temp = A.congNgay(n);
		temp.hienThi();
	}
}