<%-- 
    Document   : info
    Created on : Mar 18, 2024, 1:14:28 PM
    Author     : ADMIN
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"/>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
    </head>
    <body>
        <%@include file="header.jsp"%>
<!--        <h2>Thông tin người dùng</h2>
        <div>
            <p><strong>Tên người dùng:</strong> <%=user.getFullname()%></p>
            <p><strong>Tài khoản:</strong> <%=user.getUsername().substring(0,2)%>******<%=user.getUsername().substring(user.getUsername().length()-2)%></p>
            <p><strong>Số điện thoại:</strong> ******<%=user.getPhone().substring(user.getPhone().length() - 3)%></p>
        </div>-->
        <div class="card d-flex justify-content-center align-items-center" style="width: 20rem; margin: 1.5rem auto">
            <img style="width: 200px; height: 200px" src="asset/images/man.png" class="card-img-top" alt="...">
            <div class="card-body">
                <h3 class="card-title mb-3">Thông tin người dùng</h3>
                <p><strong>Tên:</strong> <%=user.getFullname()%></p>
                <p><strong>Tài khoản:</strong> <%=user.getUsername().substring(0,2)%>******<%=user.getUsername().substring(user.getUsername().length()-2)%></p>
                <p><strong>Số điện thoại:</strong> ******<%=user.getPhone().substring(user.getPhone().length() - 3)%></p>
                <%if(user.getIsStaff() == 1){%>
                    <p><strong>Vai trò:</strong> Nhân viên</p>
                <%}else if(user.getIsAdmin() == 1){%>
                    <p><strong>Vai trò:</strong> Quản trị viên</p>
                <%}else if(user.getIsAdmin() == 0 && user.getIsStaff() == 0){%>
                    <p><strong>Vai trò:</strong> Khách hàng</p>
                <%}%>
            </div>
        </div>
        <%@include file="footer.jsp" %>
