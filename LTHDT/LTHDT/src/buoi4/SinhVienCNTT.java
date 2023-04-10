package buoi4;
import java.util.Scanner;

import buoi2.Date;
import buoi3.SinhVien;

public class SinhVienCNTT extends SinhVien {
	private String taikhoan, matkhau, email;
	public SinhVienCNTT(){
		super();
		taikhoan = new String();
		matkhau = new String();
		email = new String();
	}
	public SinhVienCNTT(String ms, String ht, Date ns, int sl, String tenhp[], String diemhp[], String tk, String mk, String mail){
		super(ms, ht, ns, sl, tenhp, diemhp);
		taikhoan = new String(tk);
		matkhau = new String(mk);
		email = new String(mail);
	}
	public SinhVienCNTT(SinhVienCNTT sv){
		super((SinhVien) sv);
		taikhoan = new String(sv.taikhoan);
		matkhau = new String(sv.matkhau);
		email = new String(sv.email);
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		super.nhapThongTin();
		super.nhapDiem();
		System.out.println("Nhap tai khoan: ");
		taikhoan = sc.nextLine();
		System.out.println("Nhap mat khau: ");
		matkhau = sc.nextLine();
		System.out.println("Nhap email: ");
		email = sc.nextLine();
	}
	public String toString(){
		return super.toString() + "\nTai khoan: " + taikhoan + "\nEmail: " +email;
		
	}
	public void doiMatKkhau(String newpass){
		matkhau = new String(newpass);
	}
	public String getEmail(){
		return email;
	}
}
