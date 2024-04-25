import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class SangB2110976De1 {
    public static void main(String[] args) throws Exception {
        //Cau 1
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap vao dia chi server:");
        String ipServerStr = kb.nextLine();
        InetAddress ipServer = InetAddress.getByName(ipServerStr);
        System.out.println("Nhap cong cua UDP Server:");
        int portUDPServer = kb.nextInt();
        kb.nextLine();
        
        //Cau 2
        DatagramSocket ds = new DatagramSocket();
        
        //Cau 3
        InetAddress localIPAddress = ds.getLocalAddress();
        byte[] b = localIPAddress.toString().getBytes();
        DatagramPacket packetLocalIP = new DatagramPacket(b, b.length, ipServer, portUDPServer);
        ds.send(packetLocalIP);

        //Cau 4
        byte[] b2 = new byte[60000];
        DatagramPacket firstPacket = new DatagramPacket(b2, 60000);
        ds.receive(firstPacket);
        //Cau 5
        byte[] b3 = new byte[60000];
        DatagramPacket secondPacket = new DatagramPacket(b3, 60000);
        ds.receive(secondPacket);
        int portTCPServer = Integer.parseInt(new String(firstPacket.getData(), 0, firstPacket.getLength()));
        String password = new String(secondPacket.getData(), 0, secondPacket.getLength());

        //Cau 6
        Socket socket = new Socket(ipServer, portTCPServer);
        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();
        Scanner sc = new Scanner(is);
        PrintStream ps = new PrintStream(os);

        //Cau 7
        ps.println(password);

        //Cau 8 va cau 9
        String notify = sc.nextLine();
        if(notify.equals("-ERR")){
            System.out.println("Mat khau sai");
        }
        else{
            int lenFile = Integer.parseInt(sc.nextLine());
            byte[] byteFile = new byte[lenFile];
            DataInputStream dis = new DataInputStream(is);
            dis.readFully(byteFile);
        //Cau 10
            File fileOutput = new File("D:/NopBai/ketqua.pdf");
            FileOutputStream fos = new FileOutputStream(fileOutput);
            fos.write(byteFile, 0, lenFile);
            System.out.println("Luu thanh cong");
            fos.close();
            dis.close();
        }
        socket.close();
        ds.close();
    }
}
