<%-- 
    Document   : booking_manage
    Created on : Mar 21, 2024, 7:49:51 AM
    Author     : ADMIN
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix   ="c" uri = "http://java.sun.com/jsp/jstl/core" %>
<%@page import = "entity.Booking"%>
<%@page import = "entity.Users"%>
<%@page import = "entity.Util"%>
<%@page import = "database.dao.booking.BookingDao"%>
<%@page import = "database.dao.user.UserDao"%>
<%@page import = "java.util.*"%>
<%@page import = "java.time.*"%>
<%@page import = "java.text.DecimalFormat"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"/>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
    </head>
    <body>
        <%@include file="../header.jsp" %>
        <%@include file="./prevent_user_access.jsp" %>
        <h2>Hóa đơn</h2>
        <div class="list" style="display: flex; justify-content: center; flex-wrap: wrap; gap: 20px; padding: 10px;">
            <%BookingDao bd = new BookingDao();
            UserDao ud = new UserDao();
            List<Booking> listBooking = bd.getAll();
            for(Booking b : listBooking){
                Users u = (Users) ud.getUser(b.getUser());%>
            <div class="item">
                <div style="display: initial; padding: 20px; border: 1px solid rgb(0,0,0,0.3); width: 350px;">
                    <p style="text-align: center; border-bottom: 1px solid rgba(0,0,0,0.3); padding-bottom: 1rem"><strong><%=u.getFullname()%></strong </p>
                    <p><strong>Số điện thoại:</strong> <%=u.getPhone()%></p>
                    <p><strong>Số phòng:</strong> <%=b.getRoom()%></p>
                    <p><strong>Ngày đặt:</strong> <%=b.getCheckin()%></p>
                    <p><strong>Ngày trả:</strong> <%=b.getCheckout()%></p>
                    <p><strong>Tổng tiền:</strong> <%=Util.formatToVND(b.getPrice())%></p>
                    <%if(b.getIsCancel() == 1){%>
                    <p class="p-3 text-danger-emphasis bg-danger-subtle border border-danger-subtle rounded-3" style="color: red">Đơn đã được hủy</p>
                    <input class="btn btn-success" type="submit" value="Hoàn tất" disabled/>
                    <input class="btn btn-primary" type="submit" value="Xác nhận" disabled/>
                    <input class="btn btn-danger" type="submit" value="Hủy đơn" disabled/>
                    <%}else if(b.getIsSuccess() == 1){%>
                    <p class="p-3 text-success-emphasis bg-success-subtle border border-success-subtle rounded-3" style="color: chartreuse">Hoàn tất</p>
                    <input class="btn btn-success" type="submit" value="Hoàn tất" disabled/>
                    <input class="btn btn-primary" type="submit" value="Xác nhận" disabled/>
                    <input class="btn btn-danger" type="submit" value="Hủy đơn" disabled/>
                    <%}else if(b.getIsConfirm() == 1){%>
                    <p class="p-3 text-primary-emphasis bg-primary-subtle border border-primary-subtle rounded-3" style="color: #1da1f2">Xác nhận đặt phòng</p>
                    <div style="display: flex; gap: 5px">
                        <form action="/Project_J2EE_NhaNghi/confirmSuccess" method="post">
                            <input type="hidden" name="id" value="<%=b.getId()%>"/>
                            <input type="hidden" name="room" value="<%=b.getRoom()%>"/>
                            <input class="btn btn-success" type="submit" value="Hoàn tất"/>
                        </form>
                        <input class="btn btn-primary" type="submit" value="Xác nhận" disabled/>
                        <form action="/Project_J2EE_NhaNghi/declineBooking" method="post">
                            <input type="hidden" name="id" value="<%=b.getId()%>"/>
                            <input type="hidden" name="room" value="<%=b.getRoom()%>"/>
                            <input class="btn btn-danger" type="submit" value="Hủy đơn" />
                        </form>
                    </div>
                    <%}else if(b.getIsCancel() == 0 && b.getIsSuccess() == 0 && b.getIsConfirm() == 0){%>
                    <p class="p-3 text-info-emphasis bg-info-subtle border border-info-subtle rounded-3" style="color: #1da1f2">Đang đặt phòng</p>
                    <div style="display: flex; gap: 5px">
                        <form action="/Project_J2EE_NhaNghi/confirmSuccess" method="post">
                            <input type="hidden" name="id" value="<%=b.getId()%>"/>
                            <input type="hidden" name="room" value="<%=b.getRoom()%>"/>
                            <input class="btn btn-success" type="submit" value="Hoàn tất" disabled/>
                        </form>
                        <form action="/Project_J2EE_NhaNghi/confirmBooking" method="post">
                            <input type="hidden" name="id" value="<%=b.getId()%>"/>
                            <input type="hidden" name="room" value="<%=b.getRoom()%>"/>
                            <input class="btn btn-primary" type="submit" value="Xác nhận" />
                        </form>
                        <form action="/Project_J2EE_NhaNghi/declineBooking" method="post">
                            <input type="hidden" name="id" value="<%=b.getId()%>"/>
                            <input type="hidden" name="room" value="<%=b.getRoom()%>"/>
                            <input class="btn btn-danger" type="submit" value="Hủy đơn" />
                        </form>
                    </div>
                    <%}%>
                </div>
            </div>
            <%}%>
        </div>
        <%@include file="../pagination.jsp" %>
        <c:if test="${not empty nofty}">
            <script>
                alert("${nofty}");
            </script>
        </c:if>
        <%@include file="../footer.jsp" %>