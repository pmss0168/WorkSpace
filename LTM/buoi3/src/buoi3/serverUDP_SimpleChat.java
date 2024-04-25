package buoi3;

import java.io.*;
import java.net.*;
import java.util.ArrayList;

public class serverUDP_SimpleChat {
	public static void main(String[] args) {
		final int port = 6868;
		ArrayList<Connected> array = new ArrayList<>();
		try {
			DatagramSocket ds = new DatagramSocket(port);
			System.out.println("Server da duoc tao o cong " + port);
			while (true) {
				byte[] b = new byte[60000];
				DatagramPacket receivePacket = new DatagramPacket(b, 60000);
				ds.receive(receivePacket);
				// Them nguoi tham gia vao trong array
				InetAddress ip = receivePacket.getAddress();
				int p = receivePacket.getPort();
				Connected connect = new Connected(ip,p);
				if(!array.contains(connect)){
					array.add(connect);
				}
				byte[] data = receivePacket.getData();
				int lendata = receivePacket.getLength();
				//Gui tin nhan cho moi nguoi ket noi den server ngoai tru nguoi gui
				for(Connected con : array){
					if(!connect.equals(con)){
						DatagramPacket sendMessage = new DatagramPacket(data,lendata,con.getIp(),con.getPort());
						ds.send(sendMessage);
					}
				}
			}
		} catch (IOException e) {

		}
	}
}
