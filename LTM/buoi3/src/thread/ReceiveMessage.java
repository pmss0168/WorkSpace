package thread;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.UnknownHostException;

public class ReceiveMessage extends Thread{
	DatagramSocket ds;
	public ReceiveMessage(DatagramSocket ds1){
		ds = ds1;
	}
	@Override
	public void run(){
		try{
			while(true){
				byte[] b = new byte[60000];
				DatagramPacket receiveMessage = new DatagramPacket(b,60000);
				ds.receive(receiveMessage);
//				byte[] b1 = receiveMessage.getData();
//				int len1 = receiveMessage.getLength();
				String message = new String(receiveMessage.getData(),0,receiveMessage.getLength());
				System.out.println("Tin nhan nhan duoc:" + message);
			}
		}
		catch(UnknownHostException e){
			
		}
		catch(IOException e){
				
		}
	}
}