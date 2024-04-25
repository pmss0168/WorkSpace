package thread;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class SendMessage extends Thread{
	DatagramSocket ds;
	public SendMessage(DatagramSocket ds1){
		ds = ds1;
	}
	@Override
	public void run(){
		try{
			Scanner sc = new Scanner(System.in);
			while(true){
				System.out.println("Nhap tin nhan can gui:");
				String message = sc.nextLine();
				if(message.equals("EXIT")){
					ds.close();
					break;
				}
				byte[] b = message.getBytes();
				int len = b.length;
				InetAddress address = InetAddress.getByName("127.0.0.1");
				int port = 6868;
				DatagramPacket sendMessage = new DatagramPacket(b, len, address, port);
				ds.send(sendMessage);
			}
		}
		catch(UnknownHostException e){
			
		}
		catch(IOException e){
				
		}
	}
}