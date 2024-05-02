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


public class MulticastFileClient {
	public static void main(String[] args) {
		try {
			//Khoi tao group 231.2.3.4 va port 23456
			InetAddress group = InetAddress.getByName("231.2.3.4");
			int port = 23456;
			MulticastSocket ms = new MulticastSocket(port);
			ms.joinGroup(group);

			//Tao file rong nhan ket qua
			File file = new File("result");
			FileOutputStream fos = new FileOutputStream(file);
			FileInputStream fis = new FileInputStream(file);
			
			int cnt = 0;
			System.out.println("Bat dau doc file gui tu server");
			while (true) {
				//Goi nhan
				byte b[] = new byte[60000];
				DatagramPacket receivePacketFirst = new DatagramPacket(b, 60000);
				ms.receive(receivePacketFirst);
				int lenFisrt = receivePacketFirst.getLength();
				boolean complete = false;

				if(lenFisrt == 0) {
					System.out.println("Dang ghi file...");
					while(true) {
						byte b1[] = new byte[60000];
						DatagramPacket receivePacketSecond = new DatagramPacket(b1, b1.length);
						ms.receive(receivePacketSecond);
						int lenSecond = receivePacketSecond.getLength();
						if (lenSecond == 0) {
							complete = true;
							break;
						}
						cnt += receivePacketSecond.getLength();
					}
				}
				//Hoan thanh, ghi file ket qua
				if (complete) {
					byte b2[] = new byte[cnt];
//					fis.read(b2);
					fos.write(b2, 0, cnt);
					break;
				}
			}
			System.out.println("Da luu file thanh cong!");
			ms.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
