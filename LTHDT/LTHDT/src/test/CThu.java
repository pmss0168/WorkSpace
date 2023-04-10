package test;
import java.util.Scanner;
public class CThu extends CNguoi {
	private int so;
	private String vtri,mua,clbo;
	private long bthang;
	public CThu() {
		super();
		so=0;
		vtri=new String();
		mua=new String();
		clbo=new String();
		bthang=0;
	}
	public CThu(CThu a) {
		super((CNguoi)a);
		so=a.so;
		vtri=new String(a.vtri);
		mua=new String(a.mua);
		clbo=new String(a.clbo);
		bthang=a.bthang;
	}
	public void nhap() {
		super.nhap();
		Scanner sc=new Scanner(System.in);
		System.out.println("Nhap vao so ao: ");
		so=sc.nextInt();
		System.out.println("Nhap vao so ban thang: ");
		bthang=sc.nextLong();
		sc.nextLine();
		System.out.println("Nhap vao vi tri: ");
		vtri=sc.nextLine();
		System.out.println("Nhap vao mua: ");
		mua=sc.nextLine();
		System.out.println("Nhap vao cau lac bo: ");
		clbo=sc.nextLine();
	}
	public void in() {
		super.in();
		System.out.println(so+"; "+vtri+"; "+mua+"; "+clbo+"; "+bthang);
	}
	public String toString() {
		return super.toString()+so+"; "+vtri+"; "+mua+"; "+clbo+"; "+bthang;
	}
	public long tinhluong() {
		long tien=0;
		if(vtri.compareTo("Thu Mon")==0)
			  tien=(tien+(7000000+3000000+bthang*5000000));
		else 
			if(vtri.compareTo("Hau Ve")==0)
			  tien=(tien+(7000000+4000000+bthang*5000000));
		else 
			if(vtri.compareTo("Trung Ve")==0)
			  tien=(tien+(7000000+4500000+bthang*5000000));
		else 
			if(vtri.compareTo("Tien Ve")==0)
			  tien=(tien+(7000000+5000000+bthang*5000000));
		else 
			if(vtri.compareTo("Tien Dao")==0) 
			  tien=(tien+(7000000+7000000+bthang*5000000));
		return (long)(tien-tien*0.1);
	}
	
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Nhap vao so cau thu: ");
		int n=sc.nextInt();
		CThu ds[];
		ds=new CThu[n];
		for(int i=0;i<n;i++) {
			System.out.println("Nhap vao thong tin cau thu "+(i+1));
			ds[i]=new CThu();
			ds[i].nhap();
		}
		for(int i=0;i<n;i++) {
			System.out.println("Thong tin cau thu: "+ds[i]);
			
		}
		for(int i=0;i<n;i++) {
			System.out.println("Tien luong cau thu: "+ds[i].tinhluong());
		}
		
	}
	
}