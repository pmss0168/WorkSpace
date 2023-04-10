package test;

import java.util.Scanner;
public class ChuyenXe {
	private int maso;
	private String tentaixe;
	private String noiden;
	private float doanhthu;
	public ChuyenXe() {
		maso=0;
		tentaixe=new String();
		noiden=new String();
		doanhthu=0.0f;
	}
	public ChuyenXe(ChuyenXe a) {
		maso=a.maso;
		tentaixe=new String(a.tentaixe);
		noiden=new String(a.noiden);
		doanhthu=a.doanhthu;
	}
	public void nhap() {
		Scanner s=new Scanner(System.in);
		System.out.println("Nhap vao ma so chuyen xe: ");
		maso=s.nextInt();
		s.nextLine();
		System.out.println("Nhap vao ten tai xe: ");
		tentaixe=s.nextLine();
		System.out.println("Nhap vao noi den: ");
		noiden=s.nextLine();
		System.out.println("Nhap vao doanh thu: ");
		doanhthu=s.nextFloat();
	}
	public void in() {
		System.out.println("ma so: "+maso+","+"ten tai xe: "+tentaixe+","+"noi den: "+noiden+","+"doanh thu:"+doanhthu);
	}
	public String toString() {
		return "ma so: "+maso+","+"ten tai xe: "+tentaixe+","+"noi den: "+noiden+","+"doanh thu:"+doanhthu;
	}
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		ChuyenXe ds[];
		System.out.println("Nhap so luong phan tu cua danh sach: ");
		int m=sc.nextInt();
		sc.nextLine();
		ds=new ChuyenXe[m];
		for(int i=0;i<m;i++) {
			System.out.println("Nhap vao chuyen xe thu "+(i+1)+":");
			ds[i]=new ChuyenXe();
			ds[i].nhap();
		}
		for(int i=0;i<m;i++) {
			System.out.println("Danh sach chuyen xe: "+ds[i]);
		}
	}

}