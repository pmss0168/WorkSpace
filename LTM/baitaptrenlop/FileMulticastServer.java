import java.io.File;
import java.io.FileInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;

public class FileMulticastServer {
    public static void main(String[] args) {
        try {
            InetAddress addressServer = InetAddress.getByName("231.2.3.4");
            int portServer = 23456;
            MulticastSocket ms = new MulticastSocket(23456);
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap dia chi file can gui");
            String filePath = kb.nextLine();
            while(true){
                File file = new File(filePath);
                long lenFile = file.length();
                byte[] byteFile = new byte[(int) lenFile];
                FileInputStream fis = new FileInputStream(file);
                fis.read(byteFile);
                //Gui goi dau
                byte[] b = new byte[0];
                DatagramPacket firstPacket = new DatagramPacket(b, 0, addressServer, portServer);
                ms.send(firstPacket);
                System.out.println("Gui goi dau: 0");
                int sumLen = 0;
                while(sumLen < lenFile){
                    byte[] b2 = new byte[60000];
                    System.arraycopy(byteFile, sumLen, b2, 0, 60000);
                    DatagramPacket packetSend = new DatagramPacket(b2, 60000, addressServer, portServer);

                }
                Thread.sleep(10000);
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }
   
}
