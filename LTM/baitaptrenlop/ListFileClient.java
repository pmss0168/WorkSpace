import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class ListFileClient {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap dia chi Server:");
            String addressServer = kb.nextLine();
            System.out.println("Nhap cong Server:");
            int portServer = kb.nextInt();
            kb.nextLine();
            while (true) {
                Socket socket = new Socket(addressServer,portServer);
                System.out.print("Nhap thu muc can gui: LIST ");
                String request = "LIST " + kb.nextLine(); 
                if(request.substring(5).equals("EXIT"))
                    break;
                InputStream is = socket.getInputStream();
                OutputStream os = socket.getOutputStream();
                Scanner sc = new Scanner(is);
                PrintStream ps = new PrintStream(os);
                ps.println(request);
                int n = Integer.parseInt(sc.nextLine());
                if(n == -1){
                    System.out.println("Thu muc khong ton tai");
                }
                else if(n == 0){
                    System.out.println("Thu muc rong");
                }
                else{
                    System.out.println("Thu muc " + request.substring(5) + " gom:");
                    for(int i = 0; i < n; i++){
                        String kq = sc.nextLine();
                        System.out.println(kq);
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
