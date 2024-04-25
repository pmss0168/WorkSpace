import java.util.Scanner;

public class LopIP {
    public static char lopDiaChiIP(String dc) {
		// Tim vi tri . dau tien
		int i = dc.indexOf('.');
		String s = dc.substring(0,i);
		int x = Integer.parseInt(s);
		if( x<= 126 )
			return 'A';
		if( x == 127)
			return 'L';
		if( x <= 191 )
			return 'B';
		if( x <= 223 )
			return 'C';
		if( x <= 239 )
			return 'D';
		return 'E';
	}

	public static void main(String[] args) {
		// Nhap 1 chuoi
		@SuppressWarnings("resource")
        Scanner kb = new Scanner(System.in);
		System.out.print("Nhap 1 dia chi IP: ");
		String str = kb.nextLine();
		// Hien thi lop cua dc IP
		System.out.println(str + " thuoc lop " +
				lopDiaChiIP(str)	);

	}
}
