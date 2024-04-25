import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;

public class CopyFile {
    public static void main(String[] args) {
        try {
            Scanner kb = new Scanner(System.in);
            System.out.println("Nhap ten file tai len:");
            String fileInput = kb.nextLine();
            System.out.println("Nhap ten file luu ve:");
            String fileOutput = kb.nextLine();
            FileInputStream fis = new FileInputStream(fileInput);
            FileOutputStream fos = new FileOutputStream(fileOutput);
            DataInputStream dis = new DataInputStream(fis);
            DataOutputStream dos = new DataOutputStream(fos);
            File file = new File(fileInput);
            int len = (int) file.length();
            byte[] b = new byte[len];
            dis.readFully(b);
            dos.write(b, 0, len);
            System.out.println("Copy file thanh cong!");
            dis.close();
            dos.close();
            kb.close();
        } catch (Exception e) {
            
        }
    }
}
