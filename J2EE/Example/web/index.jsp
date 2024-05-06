<%-- 
    Document   : index
    Created on : Apr 24, 2024, 4:42:28 PM
    Author     : ADMIN
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="entity.Students" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <div style="color:red;">
            <c:if test="${not empty notify}">
                ${notify}
            </c:if>
        </div>
        <h1>Đăng nhập</h1>
        <form action="./login" method="post">
            <table>
                <tr>
                    <td>MSSV:</td>
                    <td>
                        <input type="text" name="mssv" required>
                    </td>
                </tr>
                <tr>
                    <td>Mật khẩu</td>
                    <td>
                        <input type="password" name="password" required>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <input type="submit" value="Gửi">
                        <input type="reset" value="Xóa">
                    </td>
                </tr>
            </table>
        </form>
    </body>
</html>
