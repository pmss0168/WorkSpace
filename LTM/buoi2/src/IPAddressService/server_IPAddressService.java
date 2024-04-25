package IPAddressService;

import java.io.IOException;
import java.net.*;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.io.*;


class ServiceIPAddress extends Thread{
	Socket socket;
	public ServiceIPAddress(Socket s1){
		socket = s1;
	}
	public void run(){
		try{
			InputStream is = socket.getInputStream();
			OutputStream os = socket.getOutputStream();
			Scanner sc = new Scanner(is);
			PrintStream ps = new PrintStream(os);
			try{
				while (true) {
					String request = sc.nextLine();
					if (request.equals("EXIT")) {
						break;
					}
					boolean flag = true;
					String[] splitRequest = request.split("\\.");
					
					if(splitRequest.length > 4 || splitRequest.length < 4){
						flag = false;
					}
					try {
						for (String e : splitRequest) {
							int number = Integer.parseInt(e);
							if (number <= 0 || number > 255) {
								flag = false;
								break;
							}
						}
					} catch (NumberFormatException e) {
						System.out.println("Loi dinh dang so!!!");
					}
					String outputString = new String();
					if (flag == true) {
						int number = Integer.parseInt(splitRequest[0]);
						if(number == 127){
							outputString = "Dia chi " + request + " tren la dia chi local";
						}
						else
							if(number >= 1 && number <= 126){
								outputString = "Dia chi " + request + " tren thuoc lop A";
							}
							else
								if(number >= 128 && number <= 191){
									outputString = "Dia chi " + request + " tren thuoc lop B";
								}
								else
									if(number >= 192 && number <= 223){
										outputString = "Dia chi " + request + " tren thuoc lop C";
									}
									else
										if(number >= 224 && number <= 239){
											outputString = "Dia chi " + request + " tren thuoc lop D";
										}
										else
											if(number >= 240 && number <= 255){
												outputString = "Dia chi " + request + " tren thuoc lop E";
											}
					}
					else{
						outputString = "Dia chi IP khong chinh xac!!!";
					}
					ps.println(outputString);
				}
			} catch (NoSuchElementException e) {
				System.out.println("Khong tim thay phan tu");
			}
			socket.close();
		}
		catch(IOException e){
			System.out.println("Loi nhap xuat");
		}
	}
	
}

public class server_IPAddressService {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(7000);
			System.out.println("Server created in port 7000");
			while (true) {
				Socket socket = ss.accept();
				System.out.println(socket.getInetAddress().toString() + "/"
						+ socket.getPort() + " connect to server!!!");
				ServiceIPAddress pv = new ServiceIPAddress(socket);
				pv.start();
				
			}
		} catch (IOException e) {
			System.out.println("Loi nhap xuat");
		}
	}
}
