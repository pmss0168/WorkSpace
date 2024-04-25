import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class UDPEchoClient1 {
    public static void main(String[] args) {
        try {
            DatagramSocket datagramSocket = new DatagramSocket();
            Scanner kb = new Scanner(System.in);
            InetAddress addressServer = InetAddress.getByName("127.0.0.1");
            int portServer = 7;
            while (true) {
                System.out.println("Nhap noi dung:");  
                String request = kb.nextLine();
                if(request.equals("EXIT"))
                    break;
                byte[] buffer = request.getBytes();
                int len = buffer.length;
                DatagramPacket requestPacket = new DatagramPacket(buffer, len, addressServer, portServer);
                datagramSocket.send(requestPacket);
                byte[] buffer2 = new byte[60000];
                DatagramPacket responsePacket = new DatagramPacket(buffer2, 60000);
                datagramSocket.receive(responsePacket);
                byte[] buffer3 = responsePacket.getData();
                int len3 = responsePacket.getLength();
                String result = new String(buffer3, 0, len3);
                System.out.println("Du lieu nhan duoc: " + result);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
