package buoi4;

import java.util.Scanner;

import buoi2.Diem;

public class DiemMau extends Diem{
	private String mau;
	public DiemMau(){
		super();
		mau = new String();
	}
	public DiemMau(int x1, int y1, String mau1){
		super(x1, y1);
		mau = new String(mau1);
	}
	public DiemMau(DiemMau dm){
		super((Diem) dm);
		mau = new String(dm.mau);
	}
	public void ganMau(String mau1){
		mau = mau1;
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		super.nhapDiem();
		System.out.println("Nhap mau: ");
		mau = sc.nextLine();
	}
	public void in(){
		super.inDiem();
		System.out.println(" Mau: " + mau);
	}
	public String toString(){
		return super.toString() + " Mau: " + mau;
	}
	public void tinhtien(int x, int y){
		super.doiDiem(x, y);
	}
}















