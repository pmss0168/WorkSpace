import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class TCPFileClient {
    public static void main(String[] args) {
        try{
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap vao dia chi Server:");
            String addressServer = kb.nextLine();
            System.out.println("Nhap vao cong Server:");
            int portServer = kb.nextInt();
            kb.nextLine();
            System.out.println("Nhap vao ten file:");
            String fileInput = kb.nextLine();
            Socket socket = new Socket(addressServer, portServer);
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            Scanner sc = new Scanner(is);
            PrintStream ps = new PrintStream(os);
            String request = "READ " + fileInput;
            ps.println(request);
            int lenResponse = Integer.parseInt(sc.nextLine());
            if(lenResponse == -1){
                System.out.println("File khong ton tai!");
            }
            else if(lenResponse == 0){
                System.out.println("File " + fileInput + " rong!");
            }
            else {
                System.out.println("Nhap file can luu:");
                String fileOutput = kb.nextLine();
                FileOutputStream fos = new FileOutputStream(fileOutput);
                DataInputStream dis = new DataInputStream(is);
                byte[] byteReader = new byte[10000];
                int sum = 0;
                while (true) {
                    int n = dis.read(byteReader);
                    if(n > 0){
                        fos.write(byteReader,0,n);
                        sum += n;
                    }
                    if(sum == lenResponse){
                        break;
                    }
                }
                System.out.println("Luu file thanh cong!");
            }
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
