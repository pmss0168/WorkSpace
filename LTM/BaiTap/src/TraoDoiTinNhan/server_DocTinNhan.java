package TraoDoiTinNhan;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class server_DocTinNhan {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(3500);
			System.out.println("Server listening on port 3500");
			while (true) {
				Socket socket = ss.accept();
				System.out.println(socket.getInetAddress().toString() + "/" + socket.getPort() + " connect to Server");
				OutputStream os = socket.getOutputStream();
				InputStream is = socket.getInputStream();
				try {
					while (true) {
						byte b[] = new byte[100000];
						int n = is.read(b);
						String message = new String(b, 0, n);
						if (message.compareTo("exit") == 0)
							break;
						os.write(b);
					}
					System.out.println(socket.getInetAddress().toString() + "/" + socket.getPort() + " ngat ket noi!!!");
					socket.close();
				} catch (Exception e) {
					System.out.println("Co loi xay ra!!!");
				}
			}

		} catch (Exception e) {
			System.out.println("Co loi xay ra!!!");
		}
	}
}
