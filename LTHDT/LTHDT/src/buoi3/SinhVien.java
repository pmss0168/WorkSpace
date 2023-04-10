package buoi3;

import java.util.Scanner;

import buoi2.Date;

public class SinhVien {
	private String mssv;
	private String hoten;
	private Date ngaysinh;
	private int soluong;
	private String []tenhp, diem;
	public SinhVien(){
		mssv = new String();
		hoten = new String();
		ngaysinh = new Date();
		soluong = 0;
		tenhp = new String[100];
		diem = new String[100];
	}
	public SinhVien(SinhVien sv){
		mssv = new String (sv.mssv);
		hoten =new String (sv.hoten);
		ngaysinh = new Date(sv.ngaysinh);
		soluong = sv.soluong;
		for(int i = 0; i < soluong; i++){
			tenhp[i] = new String(sv.tenhp[i]);
			diem[i] = new String(sv.diem[i]);
		}
	}
	public SinhVien(String ms, String ht, Date ns, int sl, String mon[], String d[]){ 
		mssv = new String (ms);
		hoten =new String (ht);
		ngaysinh = new Date(ns);
		soluong = sl;
		for(int i = 0; i < soluong; i++){
			tenhp[i] = new String(mon[i]);
			diem[i] = new String(d[i]);
		}
	}
		
	public int laySoLuong(){
		return soluong;
	}
	public void nhapThongTin(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so sinh vien: ");
		mssv = sc.nextLine();
		System.out.println("Nhap ho ten sinh vien: ");
		hoten = sc.nextLine();
		System.out.println("Nhap ngay sinh sinh vien: ");
		ngaysinh.nhap();
	}
	public void nhapDiem(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong hoc phan: ");
		soluong = sc.nextInt();
		sc.nextLine();
		for(int i = 0; i< soluong; i++){
			System.out.println("Nhap ten hoc phan: ");
			tenhp[i] = sc.nextLine();
			System.out.println("Nhap diem hoc phan: ");
			diem[i] = sc.nextLine();
		}
	}
	public String toString(){
		String s;
		s = "[" + mssv + " - " + hoten + " - " + ngaysinh + " - " + soluong;
		for(int i = 0; i< soluong; i++){
			s += " - " + tenhp[i] + " - " + diem[i] ;
		}
		s += "]";
		return s;
	}
	public String tachten() {
		hoten.trim();
		int p = hoten.lastIndexOf(" ");
		return hoten.substring(p+1);
	}
	public float dtb(){
		float dtb = 0;
		for(int i = 0; i< soluong; i++){
			if(diem[i].compareTo("A") == 0)
				dtb += 4.0;
			else
				if(diem[i].compareTo("B+") == 0)
					dtb += 3.5;
				else
					if(diem[i].compareTo("B") == 0)
						dtb += 3.0;
					else
						if(diem[i].compareTo("C+") == 0)
							dtb += 2.5;
						else
							if(diem[i].compareTo("C") == 0)
								dtb += 2.0;
							else
								if(diem[i].compareTo("D") == 0)
									dtb += 1.5;
								else
									if(diem[i].compareTo("D+") == 0)
										dtb += 1.0;
									else
										if(diem[i].compareTo("F") == 0)
											dtb +=0.0;
		}
		return dtb;
	}
	public void dangky(String mon, String diemso){
		if(soluong >= tenhp.length-1)
			System.out.println("Mang day!!!");
		else
			for(int i = 0; i< soluong ; i++){
				if(tenhp[i].compareTo(mon) == 0){
					System.out.println("Mon hoc da co!!!");
					break;
				}
				else{
					tenhp[soluong] = new String(mon);
					diem[soluong] = new String(diemso);
				}
			}
		soluong++;
	}
//	public void xoa(String mon){
//		for(int i = 0; i< soluong; i++){
//			if(tenhp[i].compareTo(mon) != 0){
//				System.out.println("Khong tim thay mon hoc!!!");
//				break;
//			}
//			else{
//				for(int j = i; j< soluong -1 ; j++){
//					tenhp[j] = new String(tenhp[j+1]);
//					diem[j] = new String(diem[j+1]);
//				}
//				soluong--;
//			}
//		}
//	}
	public void xoa(String mon){
		int i;
		for(i = 0; i< soluong; i++){
			if(tenhp[i].compareTo(mon) == 0)
				break;
		}
		if(i < soluong){
			for(int j = i; j< soluong; j++){
				tenhp[j] = new String(tenhp[j+1]);
				diem[j] = new String(diem[j+1]);
			}
			soluong--;
		}
	}
	
}














