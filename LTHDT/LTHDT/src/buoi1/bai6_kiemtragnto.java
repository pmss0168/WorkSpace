package buoi1;

import java.util.Scanner;

public class bai6_kiemtragnto {
	public static boolean ngto(int a) {
		if(a < 2) return false;
		for(int i = 2; i < (int) Math.sqrt(a); i++ ) {
			if(a % i == 0)
				return false;
		}
		return true;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();
		if(ngto(number))
			System.out.println(number + " la so nguyen to!!!");
		else
			System.out.println(number + " khong la so nguyen to!!!");
		System.out.println(Integer.toBinaryString(number));
	}
}
