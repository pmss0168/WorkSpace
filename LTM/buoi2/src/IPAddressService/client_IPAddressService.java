package IPAddressService;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class client_IPAddressService {
	public static void main(String[] args) {
		try{
			Scanner kb = new Scanner(System.in);
			System.out.println("Nhap dia chi cua server:");
			String serverAddress = kb.nextLine();
			Socket socket = new Socket(serverAddress, 7000);
			InputStream is = socket.getInputStream();
			OutputStream os = socket.getOutputStream();
			Scanner sc = new Scanner(is);
			PrintStream ps = new PrintStream(os);
			while(true){
				System.out.println("Nhap vao dia chi IP can xac dinh:");
				String ipAddress = kb.nextLine();
				if(ipAddress.equals("EXIT")){
					break;
				}
				ps.println(ipAddress);
				
				String outputString = sc.nextLine();
				System.out.println(outputString);
			}
			socket.close();
		}
		catch(IOException e){
			System.out.println("Loi nhap xuat!");
		}
	}
}
