package buoi1;

import java.util.Scanner;

public class bai5_ptbac1_ptbac2 {
	public static  void ptbac1(int a, int b) {
		if(a == 0) {
			if(b == 0) {
				System.out.println("Phuong trinh da cho co vo so nghiem!!!");
			}
			else
				System.out.println("Phuong trinh da cho vo nghiem!!!");
		}
		else
			System.out.println("Phuong trinh da cho co mot nghiem duy nhat: " + (-b*1.0/a));
	}
	
	public static void ptbac2(int a, int b, int c) {
		double delta = 0;
		delta = b*b-(4*a*c);
		if(a == 0) {
			ptbac1(b,c);
		}
		else {
			if(delta < 0) {
				System.out.println("Phuong trinh da cho vo nghiem!!!");
			}
			else
				if(delta == 0) {
					System.out.println("Phuong trinh da cho co nghiem kep: x1 = x2 = " + (-b*1.0/(a*2)));
				}
				else
					System.out.println("Phuong trinh da cho co hai nghiem phan biet: x1 = " + ((-b*1.0 + Math.sqrt(delta))/(2*a)) + " x2 = " + ((-b*1.0 - Math.sqrt(delta))/(2*a)) );
		}
	}
	public static void main(String[] args) {
		int a,b,c;
		Scanner sc = new Scanner(System.in);
		a=sc.nextInt();
		b=sc.nextInt();
		c=sc.nextInt();
		ptbac1(a,b);
		ptbac2(a,b,c);
	}
}
