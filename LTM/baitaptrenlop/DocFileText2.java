import java.io.File;
import java.io.FileInputStream;
import java.util.Scanner;

public class DocFileText2 {
    public static void main(String[] args) throws Exception {
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap vao ten file:");
        String fileName = kb.nextLine();
        FileInputStream fis = new FileInputStream(fileName);
        System.out.println("Noi dung file:");
        File file = new File(fileName);
        int len = (int) file.length();
        byte b[] = new byte[len];
        int n = fis.read(b);
        if(n == len){
            String result = new String(b,0,n);
            System.out.println(result);
        }
        else{
            System.out.println("Chua doc het noi dung file!");
        }
    }
}
