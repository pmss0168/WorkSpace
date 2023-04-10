package buoi1;

import java.util.Scanner;

public class bai4_tinhtong {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a=0,b=0;
		String a1,b1;
		boolean bool=false;
		do {
			a1=sc.nextLine();
			b1=sc.nextLine();
			bool=true;
			try {
				a=Integer.parseInt(a1);
				b=Integer.parseInt(b1);
			}
			catch(NumberFormatException e){
				System.out.println("Sai dinh dang nhap lai!!!");
				bool=false;
			}
		}while(!bool);
			System.out.println("Tong = " + (a+b));
		
	}
}
