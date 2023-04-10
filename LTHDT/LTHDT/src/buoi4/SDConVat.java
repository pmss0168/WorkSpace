package buoi4;

import java.util.Scanner;

public class SDConVat {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong con vat: ");
		int n = sc.nextInt();
		ConVat dv[] = new ConVat[n];
		for(int i = 0; i < n; i++){
			System.out.println("Nhap con vat thu " + (i+1));
			System.out.println("Chon con vat muon nhap Bo(1), Heo(2), De(3), Ga(4):");
			int c = sc.nextInt();
			switch(c){
			case 1:
				dv[i] = new Bo();
				break;
			case 2:
				dv[i] = new Heo();
				break;
			case 3:
				dv[i] = new De();
				break;
			case 4:
				dv[i] = new Ga();
				break;
			}
			dv[i].nhap();
		}
		for(ConVat d: dv){
			d.in();
		}
	}
}	
