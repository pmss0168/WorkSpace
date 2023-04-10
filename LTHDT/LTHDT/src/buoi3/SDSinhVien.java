package buoi3;

import java.util.Scanner;

public class SDSinhVien {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		SinhVien a;
//		a = new SinhVien();
//		System.out.println("Nhap thong tin sinh vien: ");
//		a.nhapThongTinh();
//		a.nhapDiem();
//		a.dangky("LTHDT", "B+");
//		System.out.println(a);
		SinhVien list[];
		int n;
		System.out.println("Nhap so phan tu sinh vien:");
		n = sc.nextInt();
		sc.nextLine();
		list = new SinhVien[100];
		for(int i = 0; i< n; i++){
			list[i] = new SinhVien();
		}
		for(int i = 0; i< n; i++){
			list[i].nhapThongTin();
			list[i].nhapDiem();
		}
		for(int i = 0; i< n; i++){
			System.out.println("Sinh vien thu " + (i+1) +" : "+ list[i] );
		}
		System.out.println("Sinh vien bi canh bao hoc vu: ");
		for(int i = 0; i< n; i++){
			if(list[i].dtb() < 1.0 || list[i].laySoLuong() == 0){
				System.out.println(list[i]);
			}
		}
		float max = 0;
		for(int i = 0; i< n; i++){
			if(max < list[i].dtb())
				max = list[i].dtb();
		}
		System.out.println("Sinh vien co diem trung binh cao nhat: ");
		for(int i = 0; i< n; i++){
			if(list[i].dtb() == max)
				System.out.println(list[i]);
		}
		for(int i = 0; i< n-1; i++){
			for(int j = i+1; j < n; j++){
				if(list[i].tachten().compareTo(list[j].tachten()) > 0){
					SinhVien at = list[i];
					list[i] = list[j];
					list[j] = at;
				}
			}
		}
		System.out.println("Danh sach sau khi sap xep: ");
		for(int i = 0; i< n; i++){
			System.out.println(list[i]);
		}
	}
}
