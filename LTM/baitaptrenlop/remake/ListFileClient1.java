import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class ListFileClient1 {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            String addressServer = "127.0.0.1";
            int portServer = 6868;
            Socket socket = new Socket(addressServer, portServer);
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            Scanner sc = new Scanner(is);
            PrintStream ps = new PrintStream(os);
            System.out.println("Nhap ten thu muc:");
            String folderPath = kb.nextLine();
            String request = "LIST " + folderPath;
            ps.println(request);
            int lenListFolder = Integer.parseInt(sc.nextLine());
            if(lenListFolder == -1){
                System.out.println("Thu muc khong ton tai!");
            }
            else if(lenListFolder == 0){
                System.out.println("Thu muc rong");
            }
            else{
                for(int i = 0; i < lenListFolder; i++){
                    String kq = sc.nextLine();
                    System.out.println(kq);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
