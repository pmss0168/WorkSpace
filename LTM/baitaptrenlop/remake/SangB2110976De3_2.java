package remake;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class SangB2110976De3_2 {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap vao cong UDP:");
            int portUDP = kb.nextInt();
            kb.nextLine();
            System.out.println("Nhap vao cong TCP:");
            int portTCP = kb.nextInt();
            kb.nextLine();
            System.out.println("Nhap vao dia chi server:");
            String server = kb.nextLine();
            InetAddress ipServer = InetAddress.getByName(server);
            DatagramSocket ds = new DatagramSocket();
            File fileInput = new File("D:/Nopbai/data.tk");
            FileInputStream fis = new FileInputStream(fileInput);
            int lenFileInput = (int)  fileInput.length();
            byte[] b1 = new byte[lenFileInput];
            fis.read(b1);
            DatagramPacket fileInputPacket = new DatagramPacket(b1, lenFileInput, ipServer, portUDP);
            ds.send(fileInputPacket);

            byte[] b2 = new byte[60000];
            DatagramPacket passPacket = new DatagramPacket(b2, 60000);
            ds.receive(passPacket);
            String pass = new String(passPacket.getData(),0,passPacket.getLength());
            Socket socket = new Socket(ipServer, portTCP);
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            Scanner sc = new Scanner(System.in);
            PrintStream ps = new PrintStream(os);
            String localAddress = InetAddress.getLocalHost().getHostAddress();
            ps.println(localAddress);
            StringBuffer strbuff = new StringBuffer(pass);
            strbuff = strbuff.reverse();
            String reversePass = strbuff.toString();
            ps.println(reversePass);
            String notify = sc.nextLine();
            if(notify.equals("-ERR")){
                System.out.println("Chung thuc that bai");
            }else{
                System.out.println("Chung thuc thanh cong");
            }
            fis.close();
            ds.close();
            socket.close();
        }catch (Exception e){
            System.out.println(e);
        }
    }
}
