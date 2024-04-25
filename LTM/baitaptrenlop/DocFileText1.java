import java.io.FileInputStream;
import java.util.Scanner;

public class DocFileText1 {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap vao ten file:");
            String fileName = kb.nextLine();
            FileInputStream fis = new FileInputStream(fileName);
            System.out.println("Noi dung cua file:");
            while (true) {
                int ch = fis.read();
                if(ch == -1)
                    break;
                System.out.print((char) ch);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
