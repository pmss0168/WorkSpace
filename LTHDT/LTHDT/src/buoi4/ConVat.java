package buoi4;

import java.util.Scanner;

public abstract class ConVat {
	 private String giong;
	 private String maulong;
	 private float cannang;
	 public abstract void keu();
	 public ConVat(){
		 giong = new String();
		 maulong = new String();
		 cannang = 0.0f;
	 }
	 public ConVat(ConVat cv){
		 giong = new String(cv.giong);
		 maulong = new String(cv.maulong);
		 cannang = cv.cannang;
	 }
	 public ConVat(String Giong, String ML, float CN){
		 giong = new String(Giong);
		 maulong = new String(ML);
		 cannang = CN;
	 }
	 public void nhap(){
		 Scanner sc = new Scanner(System.in);
		 System.out.println("Nhap giong: ");
		 giong = sc.nextLine();
		 System.out.println("Nhap mau long: ");
		 maulong = sc.nextLine();
		 System.out.println("Nhap can nang: ");
		 cannang = sc.nextInt();
	 }
	 public void in(){
		 System.out.println("Giong: " + giong);
		 System.out.println("Mau long: " + maulong);
		 System.out.println("Can nang: " + cannang);
		 keu();
	 }
//	 public String toString(){
//		 return "Giong: " + giong + "\nMau long: " + maulong + "\nCan nang: " + cannang + keu();
//	 }
}







