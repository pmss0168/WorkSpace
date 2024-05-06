/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package database;

import entity.Students;
import entity.Subjects;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author ADMIN
 */
public class DAO {
    PreparedStatement ps = null;
    ResultSet rs = null;
    public Students checkExists(String mssv, String password){
        try{
            Connection con = new DBO().getConnect();
            String sql = "SELECT * FROM student where mssv=? and password=?";
            ps = con.prepareStatement(sql);
            ps.setString(1, mssv);
            ps.setString(2, password);
            rs = ps.executeQuery();
            if(rs.next()){
                return new Students(rs.getString("mssv"), rs.getString("password"), rs.getString("fullname"), rs.getString("class"));
            }
        }catch(Exception e){
            System.out.println(e);
        }
        return null;
    }
    public List<Subjects> myListSubject(String mssv){
        List<Subjects> list = new ArrayList<>();
        try{
            String sql = "SELECT * FROM study s join subject sb on s.subject = sb.subjectname where mssv = ?";
            Connection con = new DBO().getConnect();
            ps = con.prepareStatement(sql);
            ps.setString(1, mssv);
            rs = ps.executeQuery();
            while(rs.next()){
                list.add(new Subjects(rs.getString("subject_id"), rs.getString("subjectname"), rs.getInt("credits")));
            }
        }
        catch(Exception e){
            System.out.println(e);
        }
        return list;
    }
}
