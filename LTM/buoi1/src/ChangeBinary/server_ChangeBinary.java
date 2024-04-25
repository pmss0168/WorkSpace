package ChangeBinary;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class server_ChangeBinary {
	public static void main(String[] args) {
		try {
			ServerSocket serverSocket = new ServerSocket(3500);
			System.out.println("Server da duoc khoi tao o cong 3500");
			while (true) {
				Socket socket = serverSocket.accept();
				System.out.println(socket.getInetAddress().toString() + "/"
						+ socket.getPort() + " connect to Server!");
				InputStream is = socket.getInputStream();
				OutputStream os = socket.getOutputStream();
				while (true) {
					byte inB[] = new byte[1000];
					int lengthIn = is.read(inB);
					String inNumber = new String(inB, 0, lengthIn);
					// System.out.println("Client gui:" + inNumber);
					if (inNumber.compareTo("exit") == 0) {
						System.out.println(socket.getInetAddress().toString() + "/"
								+ socket.getPort() + " disconnect to Server!");
						socket.close();
						break;
					}
					try {
						Integer number = Integer.parseInt(inNumber);
						byte outB[] = new byte[1000];
						if ((number instanceof Integer) == true) {
							String result = (String) Integer
									.toBinaryString(number);
							// System.out.println(result);
							outB = result.getBytes();
							os.write(outB);
						}
					} catch (NumberFormatException e) {
						byte outB[] = new byte[1000];
						String result = "Khong phai la so nguyen";
						outB = result.getBytes();
						os.write(outB);
					}
				}
			}
		} catch (Exception e) {
			System.out.println("Loi!!!");
		}

	}
}
