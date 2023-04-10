package buoi3;

import java.util.Scanner;

public class Gach {
	private String maso;
	private String mau;
	private int soluong, dai, ngang;
	private long gia;
	public Gach(){
		maso = new String();
		mau = new String();
		soluong = 0;
		dai = 1;
		ngang = 1;
		gia = 0;
	}
	public Gach(Gach g){
		maso = g.maso;
		mau = g.mau;
		soluong = g.soluong;
		dai = g.dai;
		ngang = g.ngang;
		gia = g.gia;
	}
	public long layGia(){
		return gia;
	}
	public int laySoLuong(){
		return soluong;
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ma so gach:");
		maso = sc.nextLine();
		System.out.println("Nhap mau gach:");
		mau = sc.nextLine();
		System.out.println("Nhap so luong gach:");
		soluong = sc.nextInt();
		System.out.println("Nhap chieu dai vien gach:");
		dai = sc.nextInt();
		System.out.println("Nhap chieu ngang vien gach:");
		ngang = sc.nextInt();
		System.out.println("Nhap gia mot hop gach:");
		gia = sc.nextLong();
	}
	public void in(){
		System.out.println("[" +maso + "-" + mau + "-" + soluong + "-" + dai + "-" + ngang + "-" + gia + "]");
	}
	public String toString(){
		return "[" +maso + "-" + mau + "-" + soluong + "-" + dai + "-" + ngang + "-" + gia + "]";
	}
	public float giaBanLe(){
		return (float)((gia/soluong) * 1.2);
	}
	public int dienTichNen(){
		return dai*ngang*soluong;
	}
	public int soLuongHop(int D, int N){
		int chieudai = D/dai;
		if(D % dai != 0)
			chieudai++;
		int chieungang = N/ngang;
		if(N % ngang != 0)
			chieungang++;
		int dientich = chieudai*chieungang;
		int soluonghop = dientich/soluong;
		if(dientich % soluong != 0)
			soluonghop++;
		return soluonghop;
	}
}

















