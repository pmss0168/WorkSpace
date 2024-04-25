package remake;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class SangB2110976De1_2 {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap dia chi server:");
            String serverStr = kb.nextLine();
            InetAddress ipAddress = InetAddress.getByName(serverStr);
            System.out.println("Nhap cong UDP server:");
            int portUDP = kb.nextInt();
            kb.nextLine();
            DatagramSocket ds = new DatagramSocket();
            String localAdress = ds.getLocalAddress().toString();
            byte[] b = localAdress.getBytes();
            DatagramPacket ipPacket = new DatagramPacket(b, b.length, ipAddress, portUDP);
            ds.send(ipPacket);

            byte[] b2 = new byte[60000];
            DatagramPacket portTCPPacket = new DatagramPacket(b2, 60000);
            ds.receive(portTCPPacket);
            int portTCP = Integer.parseInt(new String(portTCPPacket.getData(),0,portTCPPacket.getLength()));
            byte[] b3 = new byte[60000];
            DatagramPacket passwordPacket = new DatagramPacket(b3, 60000);
            ds.receive(passwordPacket);
            String password = new String(passwordPacket.getData(),0,passwordPacket.getLength());
            Socket socket = new Socket(ipAddress, portTCP);
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            Scanner sc = new Scanner(is);
            PrintStream ps = new PrintStream(os);
            ps.println(password);
            String notify = sc.nextLine();
            if(notify.equals("-ERR")){
                System.out.println("Mat khau sai");
            }
            else{
                int lenFile = Integer.parseInt(sc.nextLine());
                byte[] b4 = new byte[lenFile];
                DataInputStream dis = new DataInputStream(is);
                dis.readFully(b4);

                File file = new File("D://NopBai/ketqua.pdf");
                FileOutputStream fos = new FileOutputStream(file);
                fos.write(b4);
                fos.close();
            }
            ds.close();
            socket.close();
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
}
