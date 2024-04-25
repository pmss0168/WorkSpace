import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

/**
 * UDPEchoSever
 */
public class UDPEchoSever {
    public static void main(String[] args) {
        try {
            final int portServer = 7;
            DatagramSocket ds = new DatagramSocket(portServer);
            byte[] b = new byte[60000];
            DatagramPacket requestPacket = new DatagramPacket(b, 60000);
            while (true) {
                ds.receive(requestPacket);
                byte[] b2 = requestPacket.getData();
                int len2 = requestPacket.getLength();
                String str = new String(b2,0,len2);
                String result = str.toUpperCase();
                byte[] b3 = result.getBytes();
                int len3 = b3.length;
                InetAddress address = requestPacket.getAddress();
                int port = requestPacket.getPort();
                DatagramPacket responsePacket = new DatagramPacket(b3, len3, address, port);
                ds.send(responsePacket);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}