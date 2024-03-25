/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package database;
import java.sql.*;

/**
 *
 * @author ADMIN
 */
public class DBO {

    public DBO() {
    }
    
    public Connection getConnection() throws Exception {
        String url = "jdbc:mysql://localhost:3306/project_j2ee?autoReconnect=true&useSSL=false";
        String dbUser = "root";
        String dbPass = "Vajl0nchjmen@";
        Class.forName("com.mysql.cj.jdbc.Driver");
        return DriverManager.getConnection(url,dbUser,dbPass);
    }
    
}
