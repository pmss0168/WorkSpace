<%-- 
    Document   : home]
    Created on : Apr 24, 2024, 5:14:48 PM
    Author     : ADMIN
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%@include file="header.jsp" %>
        <h1>Hello <%=sv.getFullname()%>!</h1>
        <table border="1">
            <tr>
                <th>MSSV</th>
                <th>Họ tên</th>
                <th>Lớp</th>
            </tr>
            <tr>
                <td><%=sv.getMssv()%></td>
                <td><%=sv.getFullname()%></td>
                <td><%=sv.getClassname()%></td>
            </tr>
        </table>
        <%@include file="footer.jsp" %>
    </body>
</html>
