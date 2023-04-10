package BaiTap;

import java.util.Scanner;

public class CThu extends CNguoi {
	private int so;
	private String vtri;
	private long bthang;
	private String mua,clbo;
	public CThu() {
		super();
		so = 0;
		vtri = new String();
		bthang = 0;
		mua = new String();
		clbo = new String();
	}
	public CThu(CThu c) {
		super(c);
		so = c.so;
		vtri = new String(c.vtri);
		bthang = c.bthang;
		mua = new String(c.mua);
		clbo = new String(c.clbo);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		super.nhap();
		System.out.println("Nhap so ao thi dau: ");
		so = sc.nextInt();
		sc.nextLine();
		System.out.println("Nhap vi tri: ");
		vtri = sc.nextLine();
		System.out.println("Nhap so bang thang: ");
		bthang = sc.nextLong();
		sc.nextLine();
		System.out.println("Nhap mua giai: ");
		mua = sc.nextLine();
		System.out.println("Nhap ten cau lac bo: ");
		clbo = sc.nextLine();
	}
	public void in() {
//		super.in();
//		System.out.println("So ao thi dau: " +so);
//		System.out.println("Vi tri: " +vtri);
//		System.out.println("So bang thang: " +bthang);
//		System.out.println("Mua giai: " +mua);
//		System.out.println("Ten cau lac bo: " +clbo);
		System.out.println("(" +super.toString()+ "; " +so+ "; " +vtri+ "; " +bthang+ "; " + mua+ "; " +clbo+ ")");
	}
	public String toString() {
		return "(" +super.toString()+ "; " +so+ "; " +vtri+ "; " +bthang+ "; " + mua+ "; " +clbo+ ")";
	}
	public long tinhLuong() {
		long lcb = 7000;
		long luong = 0;
		String vt = new String(vtri.toLowerCase());
		if(vt.compareTo("thu mon") == 0)
			luong = lcb +3000;
		else 
			if(vt.compareTo("hau ve") == 0)
				luong = lcb +4000;
			else
				if(vt.compareTo("trung ve") == 0)
					luong = lcb +4500;
				else
					if(vt.compareTo("tien ve") == 0)
						luong = lcb +5000;
					else
						if(vt.compareTo("tien dao") == 0)
							luong = lcb +7000;
		if(bthang > 0) {
			luong += bthang*500;
		}
		return (long) (luong - luong*0.1);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong phan tu cua danh sach: ");
		int n = sc.nextInt();
		sc.nextLine();
		CThu ds[] = new CThu[n];
		for(int i =0; i < n; i++) {
			System.out.println("Nhap cau thu thu " +(i+1)+ " : ");
			ds[i] = new CThu();
			ds[i].nhap();
		}
		for(CThu ct : ds) {
			ct.in();
		}
		//hien thi ds luong cua cac cau thu
		int i = 0;
		for(CThu ct : ds) {
			System.out.println("Cau thu thu " +(i+1)+ " : ");
			System.out.println(ct.getHten());
			System.out.println(ct.tinhLuong());
			i++;
		}
		//thong ke so bang thang o 3 cap do tuoi cho moi mua giai
		for(CThu ct : ds) {
			
		}
	}
}














