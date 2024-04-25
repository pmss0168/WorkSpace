package ChangeBinary;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class client_ChangeBinary {
	public static void main(String[] args) {
		try {
			Socket socket = new Socket("127.0.0.1", 3500);
			Scanner sc = new Scanner(System.in);
			InputStream is = socket.getInputStream();
			OutputStream os = socket.getOutputStream();
			while (true) {
				System.out.print("Nhap vao mot so nguyen:");
				String number = sc.nextLine();
				if(number.isEmpty())
					continue;
				byte inB[] = number.getBytes();
				os.write(inB);
				if (number.compareTo("exit") == 0) {
					System.out.println("Ngat ket noi client!");
					break;
				}
				byte outB[] = new byte[1000];
				int n = is.read(outB);
				String outBinary = new String(outB, 0, n);
				System.out.println("Chuoi nhan duoc:");
				System.out.println(outBinary);

			}
			socket.close();

		} catch (Exception e) {
			System.out.println("Loi!!!");
		}
	}
}
