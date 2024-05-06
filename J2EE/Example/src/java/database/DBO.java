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
    final String DB_HOST = "localhost:3307";
    final String DB_USER = "root";
    final String DB_PASS = "";
    final String DB_NAME = "example";
    public Connection getConnect() throws Exception{
        String URL = "jdbc:mysql://" + DB_HOST + "/" + DB_NAME;
        Class.forName("com.mysql.cj.jdbc.Driver");
        return DriverManager.getConnection(URL, DB_USER, DB_PASS);
    }
}
