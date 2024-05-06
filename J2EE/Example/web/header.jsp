<%-- 
    Document   : header
    Created on : Apr 24, 2024, 5:48:37 PM
    Author     : ADMIN
--%>
<%@page import="entity.Students" %>
    <% Students sv =  (Students) session.getAttribute("account");
    if(sv == null){
        response.sendRedirect("./index.jsp");
    }
    else{
    %>
    <nav>
        <ul>
            <li><a href="./logout">??ng xu?t</a></li>
            <li><a href="./loadStudy">Thêm h?c ph?n</a></li>
        </ul>
    </nav>
