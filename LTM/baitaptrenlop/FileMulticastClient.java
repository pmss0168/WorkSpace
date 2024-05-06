import java.io.*;
import java.net.*;

public class FileMulticastClient {

    public static void main(String[] args) {
        try {
            InetAddress groupAddress = InetAddress.getByName("231.2.3.4");
            System.out.println("Tao xong duong dan");
            MulticastSocket ms = new MulticastSocket(23456);
            System.out.println("tao xong cong");
            // DatagramSocket ds = new DatagramSocket();
            System.out.println("Tao xong data socket");
            ms.joinGroup(groupAddress);
            System.out.println("Tham gia group thanh cong");
            byte b[] = new byte[60000];
            int flag = 0;
            File file = null;
            String fileName;
            while (true) {
                System.out.println("Bat dau nhan goi");
                DatagramPacket goinhan = new DatagramPacket(b, 60000);
                ms.receive(goinhan);
                System.out.println("Nhan goi");
                byte bNhan[] = goinhan.getData();
                int lengthNhan = goinhan.getLength();
                if (lengthNhan == 0) {
                    if (flag == 0) {
                        flag = 1;
                    } else {
                        break;
                    }
                } else {
                    String result = new String(bNhan, 0, lengthNhan);
                    System.out.println("Noi dung goi " + result);
                    if (flag == 1) {

                        if (result.substring(0, 4).equals("file")) {
                            fileName = result.substring(4, result.length()).trim();
                            file = new File("Result" + fileName);
                            System.out.println("Tao ten file");
                        }
                        if (file != null) {
                            if (!file.exists()) {
                                file.createNewFile();
                                System.out.println("Tao file");
                                System.out.println("Bo buoc nay");
                            } else {
                                try {
                                    FileWriter fw = new FileWriter(file, true);
                                    BufferedWriter bw = new BufferedWriter(fw);
                                    bw.write(result);
                                    bw.close();
                                } catch (NullPointerException e) {
                                    System.out.println("Bo qua doc file khi chua duoc khoi tao");
                                }
                            }
                        }
                    }

                }
            }
            ms.leaveGroup(groupAddress);
        } catch (IOException e) {
            System.out.println("Loi nhap xuat");
        }

    }

}