import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class UDPEchoClient {
    public static void main(String[] args){
        try{
            Scanner kb = new Scanner(System.in);
            DatagramSocket ds = new DatagramSocket();
            System.out.println("Nhap dia chi Server:");
            String strAddress = kb.nextLine();
            InetAddress addressServer = InetAddress.getByName(strAddress);
            System.out.println("Nhap dia chi server:");
            int portServer = kb.nextInt();
            kb.nextLine();
            while(true){
                System.out.println("Nhap chuoi can gui:");
                String str = kb.nextLine();
                if(str.equals("EXIT"))
                    break;
                byte[] b = str.getBytes();
                int len = b.length;
                DatagramPacket request = new DatagramPacket(b, len, addressServer, portServer);
                ds.send(request);
                byte[] b2 = new byte[60000];
                DatagramPacket response = new DatagramPacket(b2, 60000);
                ds.receive(response);
                byte[] b3 = response.getData();
                int len3 = response.getLength();
                String result = new String(b3,0,len3);
                System.out.println("Ket qua chuoi nhan duoc: " + result);
            }
        }
        catch(Exception e){

        }
    }
}
