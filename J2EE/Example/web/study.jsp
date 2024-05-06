<%-- 
    Document   : study
    Created on : Apr 24, 2024, 5:30:03 PM
    Author     : ADMIN
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%@include file="header.jsp" %>
        <h1>Thêm học phần</h1>
        <form action="./addSubject" method="post">
            <table>
                <tr>
                    <td>Tên học phần:</td>
                    <td>
                        <input type="text" name="mahp">
                    </td>
                    <td>
                        <input type="submit" value="Gửi">
                    </td>
                </tr>
            </table>
        </form>
        <table border="1">
            <c:forEach var="subject" items="${listSubject}">
                <tr>
                    <td>${subject.getId()}</td>
                    <td>${subject.getName()}</td>
                    <td>${subject.getCredits()}</td>
                </tr>
            </c:forEach>
        </table>
        <%@include file="./footer.jsp" %>
    </body>
</html>
