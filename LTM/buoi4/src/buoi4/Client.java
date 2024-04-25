package buoi4;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;


public class Client {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) {
		try {
			InetAddress diachi = InetAddress.getByName("231.2.3.4");
			int port = 23456;
			MulticastSocket ms = new MulticastSocket(port);

			ms.joinGroup(diachi);

			File f = new File("result");
			FileOutputStream fos = new FileOutputStream(f);
			FileInputStream fis = new FileInputStream(f);
			
			int cnt = 0;
			
			while (true) {
				byte b[] = new byte[1];
				DatagramPacket goiNhan1 = new DatagramPacket(b, 1);
				ms.receive(goiNhan1);
				int len1 = goiNhan1.getLength();
				boolean complete = false;

				while (len1 == 0) {
					System.out.println("Dang ghi file...");
					byte b1[] = new byte[60000];
					DatagramPacket goiNhan2 = new DatagramPacket(b1, b1.length);
					ms.receive(goiNhan2);
					int len2 = goiNhan2.getLength();
					if (len2 == 0) {
						complete = true;
						break;
					}
					fos.write(goiNhan2.getData());
					cnt += goiNhan2.getLength();
				}
				if (complete) {
					byte b2[] = new byte[cnt];
					fis.read(b2);
					@SuppressWarnings("resource")
					FileOutputStream tam = new FileOutputStream("kq");
					tam.write(b2, 0, cnt);
					break;
				}
			}
			ms.close();
			fis.close();
			fos.close();
			f.delete();
			System.out.println("Da luu file thanh cong!");
		} catch (UnknownHostException e) {
			System.out.println("Loi dia chi server!");
		} catch (FileNotFoundException e) {
			System.out.println("Loi doc file!");
		} catch (IOException e) {
			System.out.println("Loi send - read file!");
		}
	}

}