package buoi4;

import java.util.Scanner;

public class SDSinhVienCNTT {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("Nhap so luong sinh vien: ");
		n = sc.nextInt();
		SinhVienCNTT ds[] = new SinhVienCNTT[n];
		for(int i = 0; i < n; i++){
			ds[i] = new SinhVienCNTT();
		}
		for(int i = 0; i < n; i++){
			ds[i].nhap();
		}
		for(int i = 0; i < n; i++){
			System.out.println(ds[i]);
		}
		sc.nextLine();
		System.out.println("Nhap email can tim: ");
		String mail = new String();
		mail = sc.nextLine();
		for(int i = 0; i < n; i++){
			if(ds[i].getEmail().compareTo(mail) == 0){
				System.out.println(ds[i]);
			}
		}
	}
}
