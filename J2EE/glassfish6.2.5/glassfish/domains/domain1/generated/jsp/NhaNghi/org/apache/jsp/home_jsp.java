package org.apache.jsp;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.jsp.*;
import entity.Users;
import entity.Util;

public final class home_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=UTF-8");
      response.setHeader("X-Powered-By", "JSP/2.3");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>JSP Page</title>\n");
      out.write("        <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css\"/>\n");
      out.write("        <script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js\"></script>\n");
      out.write("        <style>\n");
      out.write("            .frontBanner h4::before{\n");
      out.write("                position: absolute;\n");
      out.write("                content: \"\";\n");
      out.write("                width: 160px;\n");
      out.write("                height: 2px;\n");
      out.write("                background: #db2a34;\n");
      out.write("                top: 0;\n");
      out.write("                right: -190px;\n");
      out.write("                top: 50%;\n");
      out.write("                transform: translateY(-50%);\n");
      out.write("\n");
      out.write("            }\n");
      out.write("            .frontBanner h4::after{\n");
      out.write("                position: absolute;\n");
      out.write("                content: \"\";\n");
      out.write("                width: 160px;\n");
      out.write("                height: 2px;\n");
      out.write("                background: #db2a34;\n");
      out.write("                top: 0;\n");
      out.write("                left: -190px;\n");
      out.write("                top: 50%;\n");
      out.write("                transform: translateY(-50%);\n");
      out.write("            }\n");
      out.write("        </style>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <style>\n");
      out.write("            a{\n");
      out.write("                text-decoration: none;\n");
      out.write("                color: #db2a34;\n");
      out.write("            }\n");
      out.write("            ul{\n");
      out.write("                margin: 0px;\n");
      out.write("            }\n");
      out.write("        </style>\n");
      out.write("        <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>\n");
      out.write("        ");
Users user = (Users)session.getAttribute("account");
                if(!Util.checkSession(session)){
      out.write("\n");
      out.write("        <div style=\"height: 100px; display: flex; justify-content: space-between; padding: 0px 1rem; box-shadow: 0px -1px 8px 1px; z-index: 99\">\n");
      out.write("            <div><img style=\"border-radius: 50%\" src=\"/asset/images/logo.png\" width=\"100px\" height=\"100px\" alt=\"logo\"/></div>\n");
      out.write("            <div style=\"display: flex; align-content: center\">\n");
      out.write("                <ul style=\"display: flex; justify-content: space-around; align-items: center; list-style: none; gap: 20px\">   \n");
      out.write("                    \n");
      out.write("                </ul>\n");
      out.write("            </div>\n");
      out.write("            <div style=\"display: flex; gap: 10px; align-items: center\">\n");
      out.write("                <p style=\"margin: 0px;\">Đăng nhập</p>\n");
      out.write("                <a href=\"/index.jsp\"><button class=\"btn btn-danger\"><i class='bx bx-log-in-circle'></i></button></a>\n");
      out.write("            </div>\n");
      out.write("        </div>\n");
      out.write("        <div style=\"position: relative; height: 600px\">\n");
      out.write("            <div class=\"frontBanner\" style=\" display: flex; flex-direction: column; align-items: center; justify-content: center;position: absolute;z-index: 2; width: 100%; height: 100%; padding: 1rem; background: rgba(0,0,0,0.5);\">\n");
      out.write("                <h1 style=\"text-align: center;color: whitesmoke; font-size: xxx-large; font-family: 'Noto Serif', serif; font-weight: 700; \">VanouS Kính Chào Quý Khách!</h1>\n");
      out.write("                <h4 style=\"position: relative; color: whitesmoke; font-family: 'Lato', sans-serif;\">Motel & Relax</h4> \n");
      out.write("                <a href=\"booking.jsp\"><button class=\"btn btn-danger\">Đặt phòng</button></a>\n");
      out.write("            </div>\n");
      out.write("            <img style=\"opacity: 0.9; object-fit: cover\n");
      out.write("                 \" src=\"/asset/images/h1_hero.jpg\" width=\"100%\" height=\"100%\" alt=\"banner\"/>\n");
      out.write("        </div>\n");
      out.write("        ");
}
                else{
      out.write("\n");
      out.write("        <div style=\"height: 100px; display: flex; justify-content: space-between; padding: 0px 1rem; box-shadow: 0px -1px 8px 1px; z-index: 99\">\n");
      out.write("            <div><img style=\"border-radius: 50%\" src=\"/asset/images/logo.png\" width=\"100px\" height=\"100px\" alt=\"logo\"/></div>\n");
      out.write("            <div style=\"display: flex; align-content: center\">\n");
      out.write("                <ul style=\"display: flex; justify-content: space-around; align-items: center; list-style: none; gap: 20px\">\n");
      out.write("                    ");
if(user.getIsAdmin() == 0 && user.getIsStaff() == 0){
      out.write("   \n");
      out.write("                    <li><a href=\"/home.jsp\">Trang chủ</a></li>\n");
      out.write("                    <li><a href=\"/booking.jsp\">Đặt phòng</a></li>\n");
      out.write("                    <li><a href=\"/bill.jsp\">Xem hóa đơn</a></li>\n");
      out.write("                        ");
}else if(user.getIsAdmin() == 1 && user.getIsStaff() == 0){
      out.write("\n");
      out.write("                    <li><a href=\"/admin/management.jsp\">Thống kê</a></li>\n");
      out.write("                    <li><a href=\"/admin/user_management.jsp\">Quản lý người dùng</a></li>\n");
      out.write("                    <li><a href=\"/admin/room_management.jsp\">Quản lý phòng</a></li>\n");
      out.write("                    <li><a href=\"/admin/category_management.jsp\">Quản lý loại phòng</a></li>\n");
      out.write("                    <li><a href=\"/admin/booking_management.jsp\">Quản lý đặt phòng</a></li>\n");
      out.write("                        ");
}else if(user.getIsAdmin() == 0 && user.getIsStaff() == 1){
      out.write("\n");
      out.write("                    <li><a href=\"/admin/management.jsp\">Thống kê</a></li>\n");
      out.write("                    <li><a href=\"/booking.jsp\">Đặt phòng</a></li>\n");
      out.write("                    <li><a href=\"/admin/booking_management.jsp\">Quản lý đặt phòng</a></li>\n");
      out.write("                        ");
}
      out.write("\n");
      out.write("                </ul>\n");
      out.write("            </div>\n");
      out.write("            <div style=\"display: flex; gap: 10px; align-items: center\">\n");
      out.write("                <p style=\"margin: 0px;\">Xin chào, <a href=\"/info.jsp\">");
      out.print(user.getFullname());
      out.write("</a></p>\n");
      out.write("                <a href=\"/logoutController\"><button class=\"btn btn-danger\"><i class='bx bx-log-out-circle'></i></button></a>\n");
      out.write("            </div>\n");
      out.write("        </div>\n");
      out.write("        <div style=\"position: relative; height: 600px\">\n");
      out.write("            <div class=\"frontBanner\" style=\" display: flex; flex-direction: column; align-items: center; justify-content: center;position: absolute;z-index: 2; width: 100%; height: 100%; padding: 1rem; background: rgba(0,0,0,0.5);\">\n");
      out.write("                <h1 style=\"text-align: center;color: whitesmoke; font-size: xxx-large; font-family: 'Noto Serif', serif; font-weight: 700; \">VanouS Kính Chào Quý Khách!</h1>\n");
      out.write("                <h4 style=\"position: relative; color: whitesmoke; font-family: 'Lato', sans-serif;\">Motel & Relax</h4> \n");
      out.write("                <a href=\"booking.jsp\"><button class=\"btn btn-danger\">Đặt phòng</button></a>\n");
      out.write("            </div>\n");
      out.write("            <img style=\"opacity: 0.9; object-fit: cover\n");
      out.write("                 \" src=\"/asset/images/h1_hero.jpg\" width=\"100%\" height=\"100%\" alt=\"banner\"/>\n");
      out.write("        </div>\n");
      out.write("        ");
}
      out.write("\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
