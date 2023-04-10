package buoi1;

import java.util.Scanner;

public class bai8_danhsach {
	public static void sort(int a[], int n) {
		for(int i = 0; i < n -1; i++ ) {
			for(int j = 0; j < n - i - 1; j++) 
				if(a[j] > a [j+1]) {
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
		}
	}
	
	public static void in(int a[], int n) {
		for(int i =0; i< n; i++) {
			System.out.print(a[i] + " ");
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n,x,i,cnt=0;
		int[] a = new int[100];
		System.out.println("Nhap vao so luong phan tu:");
		n = sc.nextInt();
		System.out.println("Nhap vao danh sach so nguyen:");
		for(i = 0; i<n ; i++) {
			a[i]=sc.nextInt();
		}
		System.out.println("Nhap vao so x can tim:");
		x=sc.nextInt();
		for(i =0 ; i< n ; i++) {
			if(x==a[i])
				cnt++;
		}
		System.out.println("So lan x xuat hien trong danh sach la:\n" + cnt);
		sort(a,n);
		System.out.println("Danh sach sau khi sap xep: ");
		in(a,n);
	}
}
