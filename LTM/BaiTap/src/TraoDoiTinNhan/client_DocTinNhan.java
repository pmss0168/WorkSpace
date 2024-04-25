package TraoDoiTinNhan;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class client_DocTinNhan {
	public static void main(String[] args) {
		try {
			Socket socket = new Socket("localhost", 3500);

			InputStream is = socket.getInputStream();
			OutputStream os = socket.getOutputStream();
			Scanner sc = new Scanner(System.in);
			while (true) {
				System.out.println("Nhap tin nhan muon gui: ");
				String message = sc.nextLine();
				if (message.isEmpty())
					continue;
				byte byteMessage[] = message.getBytes();
				os.write(byteMessage);
				if (message.compareTo("exit") == 0)
					break;
				byte[] b = new byte[100000];
				int n = is.read(b); // So luong byte nhan duoc
				String receiveMessage = new String(b, 0, n);
				System.out.println("Tin nhan nhan duoc: " + receiveMessage);

			}
			System.out.println("Ngat ket noi toi server!!!");
			socket.close();
		} catch (Exception e) {
			System.out.println("Co loi xay ra!!!");
		}
	}

}
