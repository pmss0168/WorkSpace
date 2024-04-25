import java.util.Scanner;
/**
 * DaoChuoi
 */
public class DaoChuoi {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap vao mot chuoi:");
        String input = kb.nextLine();
        StringBuffer buffer = new StringBuffer(input);
        buffer = buffer.reverse();
        String result = buffer.toString();
        System.out.println("Chuoi ket qua: " + result);
    }
    
}