import java.net.*;
import java.io.*;
import java.util.*;
public class FileUDPServer {
    public static void main(String[] args) {
		try {
			InetAddress address = InetAddress.getByName("231.2.3.4");
			int port = 23456;
			DatagramSocket ds = new DatagramSocket();
			Scanner sc = new Scanner(System.in);
			System.out.println("Nhap ten file: ");
			String fileName = sc.nextLine();
			while (true) {

				if (new File(fileName).exists() && new File(fileName).isFile()) {
					System.out.println("File da ton tai");
					FileInputStream fis = new FileInputStream(fileName);
					int len = (int) (new File(fileName).length());
					DataInputStream dis = new DataInputStream(fis);

					if (len > 0) {
						DatagramPacket goigui = null;
						byte bFile[] = new byte[len];
						dis.readFully(bFile);
						byte byteNameFile[] = ("file" + fileName).getBytes();
						goigui = new DatagramPacket(byteNameFile, byteNameFile.length, address, port);
						ds.send(goigui);
						System.out.println("da gui goi dau");
						int i = 0;
						while (i < len / 60000 + 1) {
							byte bTemp[] = null;
							if (len < 60000) {
								bTemp = new byte[len];
								System.arraycopy(bFile, (int) (i * 60000), bTemp, 0, len);
								System.out.println("Gui goi nho");
							} else {
								bTemp = new byte[60000];
								System.arraycopy(bFile, (int) (i * 60000), bTemp, 0, 60000);
								System.out.println("gui goi lon");
							}

							// for(int j = 0; j <= 60000; j++){
							// bTemp[j]=bFile[i*6000+j];
							// }
							System.out.println(new String(bTemp));
							goigui = new DatagramPacket(bTemp, bTemp.length, address, port);
							ds.send(goigui);
							i++;
						}
						byte b[] = new byte[1];
						goigui = new DatagramPacket(b, 0, address, port);
						ds.send(goigui);
					}
				}
				Thread.sleep(30 * 1000);
				System.out.println("thanh cong");
			}
		} catch (IOException e) {
			System.err.println("Loi nhap xuat");
		} catch (InterruptedException e) {
			System.out.println("Loi khi nghi!!");
		}
	}
}
