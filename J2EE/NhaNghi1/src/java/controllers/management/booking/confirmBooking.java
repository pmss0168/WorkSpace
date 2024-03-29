/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package controllers.management.booking;

import database.dao.booking.BookingDao;
import database.dao.room.RoomDao;
import entity.Booking;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

/**
 *
 * @author ADMIN
 */
@WebServlet(name = "confirmBooking", urlPatterns = {"/confirmBooking"})
public class confirmBooking extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        request.setCharacterEncoding("UTF-8");
        final int isNotCancel = 0;
        final int isConfirm = 1;
        final int isNotSuccess = 0;
        final int isBooking = 1;
        int id = Integer.parseInt(request.getParameter("id"));
        int room = Integer.parseInt(request.getParameter("room"));
        BookingDao bd = new BookingDao();
        RoomDao rd = new RoomDao();
        Booking b = bd.get(id).get();
        if(b.getIsCancel() == 0 && b.getIsSuccess() == 0 && b.getIsConfirm() == 0){
            bd.changeStatus(id, isNotCancel, isNotSuccess, isConfirm);
            rd.changeStatus(room, isBooking);
            request.setAttribute("nofty", "Xác nhận đặt phòng");
            request.getRequestDispatcher("./admin/booking_management.jsp").forward(request, response);
        }else{
            request.getRequestDispatcher("./admin/booking_management.jsp").forward(request, response);
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}