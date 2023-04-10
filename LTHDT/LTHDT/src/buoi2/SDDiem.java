package buoi2;

public class SDDiem {
	public static void main(String[] args) {
		Diem A = new Diem(3,4);
		System.out.println("Toa do diem A:");
		A.inDiem();
		Diem B = new Diem();
		System.out.println("Nhap toa do diem B:");
		B.nhapDiem();
		System.out.println("Toa do diem B:");
		B.inDiem();
		Diem C = new Diem(-B.giaTriX(), -B.giaTriY());
		C.inDiem();
		System.out.println("Khoang cach tu B den goc toa do:");
		System.out.println(B.khoangCach());
		System.out.println("Khoang cac tu A den B:");
		System.out.println(A.khoangCach(B));
	}
}