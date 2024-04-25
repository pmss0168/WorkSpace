import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class SangB2110976De3 {
    public static void main(String[] args) throws Exception {
        //Cau 1
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap cong UDP Server:");
        int portUDPServer = kb.nextInt();
        kb.nextLine();
        //Cau 2
        System.out.println("Nhap cong TCP Server:");
        int portTCPServer = kb.nextInt();
        kb.nextLine();
        System.out.println("Nhap vao dia chi Server:");
        String ipStr = kb.nextLine();
        InetAddress ipServer = InetAddress.getByName(ipStr);
        //Cau 3
        DatagramSocket ds = new DatagramSocket();
        //Cau 4
        File file = new File("D:/NopBai/data.fk");
        FileInputStream fis = new FileInputStream(file);
        int lenFile = (int) file.length();
        byte[] bufFile = new byte[lenFile];
        fis.read(bufFile);
        DatagramPacket filePacket = new DatagramPacket(bufFile, lenFile, ipServer, portUDPServer);
        //Cau 5
        ds.send(filePacket);
        //Cau 6
        byte[] b1 = new byte[60000];
        DatagramPacket firstPacket = new DatagramPacket(b1, 60000);
        ds.receive(firstPacket);
        String password = new String(firstPacket.getData(),0,firstPacket.getLength());
        //Cau 7
        Socket socket = new Socket(ipServer, portTCPServer);
        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();
        Scanner sc = new Scanner(is);
        PrintStream ps = new PrintStream(os);
        //Cau 8
        // String localAddress = InetAddress.getLocalHost().getHostAddress();
        String localAddres = socket.getLocalAddress().getHostAddress();
        ps.println(localAddres);
        //Cau 9
        StringBuffer stringBuffer = new StringBuffer(password);
        stringBuffer = stringBuffer.reverse();
        String reversePassword = stringBuffer.toString();
        ps.println(reversePassword);
        //Cau 10
        String notify = sc.nextLine();
        if(notify.equals("-ERR")){
            System.out.println("Chung thuc that bai");
        }
        else{
            System.out.println("Chung thuc thanh cong");
        }
        ds.close();
        socket.close();
        fis.close();
    }
}
