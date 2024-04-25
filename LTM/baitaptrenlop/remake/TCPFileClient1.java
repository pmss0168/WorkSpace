import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

import javax.xml.crypto.Data;

public class TCPFileClient1 {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            String addressServer = "127.0.0.1";
            int portServer = 32024;
            Socket socket = new Socket(addressServer, portServer);
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            Scanner sc = new Scanner(is);
            PrintStream ps = new PrintStream(os);
            System.out.println("Nhap ten file can luu:");
            String fileName = kb.nextLine();
            String request = "READ " + fileName;
            ps.println(request);
            int len = Integer.parseInt(sc.nextLine());
            if(len == -1){
                System.out.println("Tep khong ton tai!");
            }
            else if(len == 0){
                System.out.println("Tep rong!");
            }
            else{
                byte[] byteReader = new byte[len];
                System.out.println("Nhap duong dan file can luu!");
                String fileOutput = kb.nextLine();
                FileOutputStream fos = new FileOutputStream(fileOutput);
                DataInputStream dis = new DataInputStream(is);
                dis.readFully(byteReader);
                DataOutputStream dos = new DataOutputStream(fos);
                dos.write(byteReader,0,len);
                System.out.println("Luu file thanh cong!");
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        
    }
}
