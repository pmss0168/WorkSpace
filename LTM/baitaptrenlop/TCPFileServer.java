import java.net.*;
import java.io.*;
import java.util.Scanner;
class TCPFileServer {
	public static void main(String[] args) {
		try {
			// Khoi tao Server Socket
			ServerSocket ss = new ServerSocket(32024);
			while(true) {
				// Chap nhan cho noi ket
				Socket s = ss.accept();
				InputStream is = s.getInputStream();
				OutputStream os = s.getOutputStream();
				Scanner sc = new Scanner(is);
				PrintStream ps = new PrintStream(os);
				// Nhan yeu cau tu Client
				String yeucau = sc.nextLine();
				// Lay ra ten file
				String tenfile = yeucau.substring(5);
				File f = new File(tenfile);
				if( f.exists() && f.isFile() ) {
					int len = (int)f.length();	// Lay kich thuoc file
					// Gui kich thuoc file
					ps.println(len);
					if(len > 0) {
						// Doc va gui noi dung file
						byte b[] = new byte[len];	
						FileInputStream f1 = new FileInputStream(tenfile);
						DataInputStream dis = new DataInputStream(f1);
						dis.readFully(b);	// Doc het ND file
						f1.close();
						DataOutputStream dos = new DataOutputStream(os);
						dos.write(b,0,len);	// Gui het ND file
					}
				}
				else
					ps.println("-1");
				// Dong noi ket voi Client
				s.close();
			}
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}
