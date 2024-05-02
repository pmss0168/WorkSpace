package buoi4;

import java.io.*;
import java.net.*;
import java.util.*;;

public class MulticastFileServer {
	public static void main(String[] args) {
		try{
			Scanner kb = new Scanner(System.in);
			InetAddress group = InetAddress.getByName("231.2.3.4");
			int port = 23456;
			MulticastSocket ms = new MulticastSocket();
			while(true){
				System.out.println("Duong dan file muon gui:");
				String filePath = kb.nextLine();
				if(filePath.equals("EXIT")){
					break;
				}
				while(true){
					//Doc file
					File file = new File(filePath);
					int lenFile = (int) file.length();
					FileInputStream fis = new FileInputStream(file);
					byte byteReadFile[] = new byte[lenFile];
					fis.read();
					//Gui goi dau
					byte startByte[] = new byte[0];
					int start = 0;
					DatagramPacket startPacket = new DatagramPacket(startByte, start, group, port);
					ms.send(startPacket);
					System.out.println("Gui goi dau");
					//Gui goi thu n
					int lenFileIndex = lenFile / 60000;
					int buffDu = (lenFile % 60000);
					int lenDu = lenFile - buffDu;
					System.out.println(lenDu +"/"+ buffDu+"/"+lenFileIndex);
					int lenRoad = 0;
 					for(int i = 0; i < lenFileIndex && lenRoad <= lenDu; i++){
							byte copy[] = new byte[60000]; 
							System.arraycopy(byteReadFile, lenRoad, copy, 0, 59999);
							DatagramPacket sendPacket = new DatagramPacket(copy, copy.length, group, port);
							ms.send(sendPacket);
							lenRoad += 60000;
  							System.out.println("Gui goi thu " + (i+1) + ' ' + lenRoad);
							
					}
					//Gui goi cuoi
					if(lenRoad != lenFile){
						byte copy[] = new byte[buffDu];
						System.arraycopy(byteReadFile, lenRoad, copy, 0, buffDu);
						DatagramPacket sendPacket = new DatagramPacket(copy, copy.length, group, port);
						ms.send(sendPacket);
						lenRoad += buffDu;
						System.out.println("Gui goi cuoi cung..." + (lenRoad));
					}
					Thread.sleep(5000);
				}
			}
			ms.close();
		}catch(Exception e){
			System.out.println(e);
		}
	}
}