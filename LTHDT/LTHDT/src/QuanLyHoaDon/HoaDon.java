package QuanLyHoaDon;

import java.util.Scanner;

public class HoaDon {
	private String tde, mso, hten;
	private Date nglap;
	private KhachHang kh;
	private ChiTiet dsCT[];
	public HoaDon() {
		tde = new String();
		mso = new String();
		hten = new String();
		nglap = new Date();
		kh = new KhachHang();
		dsCT = new ChiTiet[20];
	}
	public HoaDon(String tieude, String maso, String hoten, Date ngaylap, KhachHang k, ChiTiet c[]) {
		tde = new String(tieude);
		mso = new String(maso);
		hten = new String(hoten);
		nglap = new Date(ngaylap);
		kh = new KhachHang(k);
		int i = 0;
		for(ChiTiet t : c) {
			if(t == null)
				break;
			else {
				dsCT[i] = t;
				i++;
			}
		}
	}
	public HoaDon(HoaDon d) {
		tde = new String(d.tde);
		mso = new String(d.mso);
		hten = new String(d.hten);
		nglap = new Date(d.nglap);
		kh = new KhachHang(d.kh);
		int i = 0;
		for(ChiTiet t : d.dsCT) {
			if(t == null)
				break;
			else {
				dsCT[i] = new ChiTiet(d.dsCT[i]);
				i++;
			}
		}
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap tieu de hoa don: ");
		tde = sc.nextLine();
		System.out.println("Nhap ma so hoa don: ");
		mso = sc.nextLine();
		System.out.println("Ho ten nguoi lap hoa don: ");
		hten = sc.nextLine();
		System.out.println("Ngay xuat hoa don: ");
		nglap.nhap();
		System.out.println("Nhap thong tin khach hang KhachHang (1), KhachHangVIP (2): ");
		int sl = sc.nextInt();
		if(sl == 1)
			kh = new KhachHang();
		else
			kh = new KhachHangVIP();
		kh.nhap();
		System.out.println("Nhap so luong chi tiet: ");
		sl = sc.nextInt();
		if(sl > dsCT.length)
			sl = dsCT.length;
		for (int i = 0; i < sl; ++i) {
			System.out.println("Nhap chi tiet thu "+(i+1)+" :");
			dsCT[i] = new ChiTiet();
			dsCT[i].nhap();
		}
	}
	public void in() {
		System.out.println("Tieu de: " +tde+ "\nMa so: " +mso+ "\nHo ten nguoi lap: " +hten);
		System.out.println("Ngay xuat hoa don: " +nglap);
		System.out.println("Khach hang mua hang: " +kh);
		System.out.println("Danh sach hang hoa: ");
		int i = 0;
		for (ChiTiet t : dsCT) {
			if(t == null) 
				break;
			else {
			System.out.println("Hang hoa thu "+(i+1)+" la: ");
			System.out.println(dsCT[i]);
			i++;
			}
		}
	}
	public String toString() {
		String s = "(" +tde+ "; " +mso+ "; " +hten+ "; " +nglap+ "; " +kh;
		int i = 0;
		for (ChiTiet t : dsCT) {
			if(t == null)
				break;
			else {
				s += "; " + dsCT[i];
				i++;
			}
		}
		s += ")";
		return s;
	}
}
