package buoi2;

import java.util.Scanner;

public class PhanSo {
	private int tu, mau;
	public PhanSo(){
		tu = 0;
		mau = 1;
	}
	public PhanSo(int tuso, int mauso){
		tu = tuso ;
		mau = mauso;
	}
	public PhanSo(PhanSo ps) {
		tu = ps.tu;
		mau = ps.mau;
	}
	private int ucln(int a, int b){
		if(b == 0) return a;
		if(a % b == 0) return b;
		return ucln(b,a%b);
	}
	private PhanSo chuanhoa(){
		PhanSo ps = new PhanSo();
		int t = ucln(tu,mau);
		ps.tu = tu/t;
		ps.mau = mau/t;
		return ps;
	}
	public void nhapPhanSo(){
		Scanner sc = new Scanner(System.in);
		boolean flag = true;
		while(flag == true){
			System.out.println("Nhap tu so:");
			tu=sc.nextInt();
			System.out.println("Nhap mau so:");
			mau=sc.nextInt();
			if(mau == 0)
				flag = false;
			else break;
		}
	}
	public void inPhanSo(){
		if(mau < 0){
			mau = -mau;
			tu = -tu;
		}
		if(tu == 0 || mau == 1)
			System.out.println(tu);
		else 
			if(tu == mau)
				System.out.println("1");
			else
				System.out.println(tu + "/" + mau);
	}
	public String toString() {
		if(mau < 0){
			mau = -mau;
			tu = -tu;
		}
		if(tu == 0 || mau == 1)
			return "" + tu;
		else 
			if(tu == mau)
				return "1";
			else
				return tu + "/" + mau;
	}
	public void nghichDao(){
		int temp = tu;
		tu = mau;
		mau = temp;
	}
	public PhanSo giaTriNghichDao(){
		PhanSo ps = new PhanSo(mau,tu);
		return ps;
	}
	public double giaTriThuc(){
		return (double)tu/mau;
	}
	public boolean lonHon(PhanSo ps){
		if(giaTriThuc() > ps.giaTriThuc())
			return true;
		return false;
	}
	public PhanSo cong(PhanSo ps){
		PhanSo temp = new PhanSo();
		temp.tu = tu*ps.mau + ps.tu*mau;
		temp.mau = mau*ps.mau;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo tru(PhanSo ps){
		PhanSo temp = new PhanSo();
		temp.tu = tu*ps.mau - ps.tu*mau;
		temp.mau = mau*ps.mau;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo nhan(PhanSo ps){
		PhanSo temp = new PhanSo();
		temp.tu = tu*ps.tu;
		temp.mau = mau*ps.mau;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo chia(PhanSo ps){
		PhanSo temp = new PhanSo();
		temp.tu = tu*ps.mau;
		temp.mau = mau*ps.tu;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo cong(int n){
		PhanSo temp = new PhanSo();
		temp.tu = tu + n*mau;
		temp.mau = mau;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo tru(int n){
		PhanSo temp = new PhanSo();
		temp.tu = tu - n*mau;
		temp.mau = mau;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo nhan(int n){
		PhanSo temp = new PhanSo();
		temp.tu = tu*n;
		temp.mau = mau;
		temp = temp.chuanhoa();
		return temp;
	}
	public PhanSo chia(int n){
		PhanSo temp = new PhanSo();
		temp.tu = tu;
		temp.mau = mau*n;
		temp = temp.chuanhoa();
		return temp; 
	}
}





















