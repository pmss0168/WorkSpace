import java.io.FileInputStream;
import java.util.Scanner;

/**
 * DocFileText3
 */
public class DocFileText3 {
    public static void main(String[] args) throws Exception {
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap vao ten file:");
        String fileName = kb.nextLine();
        FileInputStream fis = new FileInputStream(fileName);
        Scanner sc = new Scanner(fis);
        System.out.println("Noi dung file:");
        try {
            while (true) {
                String str = sc.nextLine();
                System.out.println(str);
            }
        } catch (Exception e) {
        }
        
    }
    
}