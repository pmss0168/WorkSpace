package buoi2;

import java.util.Scanner;

public class SDPhanSo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PhanSo A = new PhanSo(3,7);
		PhanSo B = new PhanSo(4,9);
		System.out.println("Phan so A co dang la:");
		A.inPhanSo();
		System.out.println("Phan so B co dang la:");
		B.inPhanSo();
		PhanSo X = new PhanSo();
		PhanSo Y = new PhanSo();
		System.out.println("Nhap phan so X:");
		X.nhapPhanSo();
		System.out.println("Nhap phan so Y:");
		Y.nhapPhanSo();
		PhanSo temp = new PhanSo();
		temp = X.giaTriNghichDao();
		System.out.println("Gia tri nghich dao cua X la:");
		temp.inPhanSo();
		System.out.println("Tong hai phan so X va Y la:");
		temp = X.cong(Y);
		temp.inPhanSo();
//---------------------------------------------------------------------
		int n;
		System.out.println("Nhap vao so n phan tu cua danh sach:");
		n = sc.nextInt();
		PhanSo ds[] = new PhanSo[n];
		for(int i = 0; i < n; i++){
			ds[i] = new PhanSo();
			ds[i].nhapPhanSo();
		}
		PhanSo tongn = new PhanSo();
		PhanSo maxps = new PhanSo();
		for(int i = 0; i < n; i++){
			tongn = tongn.cong(ds[i]);
			if(ds[i].lonHon(maxps))
				maxps = ds[i];
		}
		System.out.println("Tong n phan so la:");
		tongn.inPhanSo();
		System.out.println("Phan so lon nhat trong danh sach la:");
		maxps.inPhanSo();
		for(int i = 0; i < ds.length-1; i++){
			for(int j = i+1; j < ds.length; j++){
				PhanSo temp2 = new PhanSo();
				if(ds[i].lonHon(ds[j])){
					temp2 = ds[i];
					ds[i] = ds[j];
					ds[j] = temp2;
				}
			}
		}
		System.out.println("Danh sach sau khi sap xep la:");
		for(int i = 0; i < ds.length; i++){
			ds[i].inPhanSo();
		}
	}
}