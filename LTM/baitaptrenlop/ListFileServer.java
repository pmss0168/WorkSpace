import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ListFileServer {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(6868);
            while(true){
                Socket socket = serverSocket.accept();
                InputStream is = socket.getInputStream();
                OutputStream os = socket.getOutputStream();
                Scanner sc = new Scanner(is);
                PrintStream ps = new PrintStream(os);
                String request = sc.nextLine();
                String folder = request.substring(5);
                File file = new File(folder);
                if(file.exists() && file.isDirectory()){
                    String[] result = file.list();
                    int len = result.length;
                    ps.println(len);
                    for(int i = 0; i < len; i++){
                        File f = new File(folder + "/" + result[i]);
                        if(f.isFile()){
                            ps.println(result[i]);
                        }
                        else{
                            ps.println("[" + result[i] + "]");
                        }
                    }
                }
                else{
                    ps.println("-1");
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
