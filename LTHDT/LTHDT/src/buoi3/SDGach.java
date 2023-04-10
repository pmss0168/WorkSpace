package buoi3;

import java.util.Scanner;

public class SDGach {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Gach ds[];
		int n;
		System.out.println("Nhap so luong danh sach:");
		n = sc.nextInt();
		ds = new Gach[n];
		for(int i = 0; i < n; i++){
			ds[i] = new Gach();
		}
		System.out.println("Nhap danh sach loai gach:");
		for(int i = 0; i< n; i++){
			ds[i].nhap();
		}
		System.out.println("Hien thi danh sach gach:");
		for(int i = 0; i < n; i++){
			ds[i].in();
		}
		System.out.println("Loai gach co chi phi lot thap nhat:");
		long min =  (long) (ds[0].giaBanLe()/(ds[0].dienTichNen()/ds[0].laySoLuong()));
		int cnt=0;
		for(int i = 0; i < n; i++){
			if(min > ds[i].giaBanLe()/(ds[i].dienTichNen()/ds[i].laySoLuong()) )
				min = (long) ds[i].giaBanLe()/(ds[i].dienTichNen()/ds[i].laySoLuong());
				cnt = i;
		}
		ds[cnt].in();
		System.out.println("Chi phi cua tung loai gach khi lot nen 5m x 20m");
		long cp =0;
		for(int i = 0; i < n; i++){
			cp = ds[i].layGia()*ds[i].soLuongHop(2000, 500);
			System.out.println("Chi phi cua loai gach thu " + (i+1) + ":" + cp);
		}
	}
}





