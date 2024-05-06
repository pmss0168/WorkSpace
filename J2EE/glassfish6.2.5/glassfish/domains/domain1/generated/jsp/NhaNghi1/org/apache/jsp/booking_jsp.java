package org.apache.jsp;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.jsp.*;
import entity.Booking;
import entity.Category;
import entity.Room;
import entity.RoomCategory;
import entity.Util;
import entity.RoomCategory;
import database.dao.DAO;
import database.dao.category.CategoryDao;
import database.dao.booking.BookingDao;
import database.dao.room.RoomDao;
import java.util.*;
import java.time.*;
import entity.Users;
import entity.Util;

public final class booking_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  static {
    _jspx_dependants = new java.util.ArrayList<String>(5);
    _jspx_dependants.add("/header.jsp");
    _jspx_dependants.add("/admin/prevent_user_access.jsp");
    _jspx_dependants.add("/prevent_access.jsp");
    _jspx_dependants.add("/pagination_table.jsp");
    _jspx_dependants.add("/footer.jsp");
  }

  private org.apache.jasper.runtime.TagHandlerPool _jspx_tagPool_c_if_test;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspInit() {
    _jspx_tagPool_c_if_test = org.apache.jasper.runtime.TagHandlerPool.getTagHandlerPool(getServletConfig());
  }

  public void _jspDestroy() {
    _jspx_tagPool_c_if_test.release();
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
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
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
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        ");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<style>\n");
      out.write("    a{\n");
      out.write("        text-decoration: none;\n");
      out.write("        color: #db2a34;\n");
      out.write("    }\n");
      out.write("    ul{\n");
      out.write("        margin: 0px;\n");
      out.write("    }   \n");
      out.write("</style>\n");
      out.write("<link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>\n");
Users user = (Users)session.getAttribute("account");
        if(!Util.checkSession(session)){
            response.sendRedirect("/index.jsp");
    }
        else{
      out.write("\n");
      out.write("<div style=\"height: 100px; display: flex; justify-content: space-between; padding: 0px 1rem; box-shadow: 0px -1px 8px 1px; z-index: 99\">\n");
      out.write("    <div><img style=\"border-radius: 50%\" src=\"/asset/images/logo.png\" width=\"100px\" height=\"100px\" alt=\"logo\"/></div>\n");
      out.write("    <div style=\"display: flex; align-content: center\">\n");
      out.write("        <ul style=\"display: flex; justify-content: space-around; align-items: center; list-style: none; gap: 20px\">\n");
      out.write("            ");
if(user.getIsAdmin() == 0 && user.getIsStaff() == 0){
      out.write("   \n");
      out.write("            <li><a href=\"/home.jsp\">Trang chủ</a></li>\n");
      out.write("            <li><a href=\"/booking.jsp\">Đặt phòng</a></li>\n");
      out.write("            <li><a href=\"/bill.jsp\">Xem hóa đơn</a></li>\n");
      out.write("                ");
}else if(user.getIsAdmin() == 1 && user.getIsStaff() == 0){
      out.write("\n");
      out.write("            <li><a href=\"/admin/management.jsp\">Thống kê</a></li>\n");
      out.write("            <li><a href=\"/admin/user_management.jsp\">Quản lý người dùng</a></li>\n");
      out.write("            <li><a href=\"/admin/room_management.jsp\">Quản lý phòng</a></li>\n");
      out.write("            <li><a href=\"/admin/category_management.jsp\">Quản lý loại phòng</a></li>\n");
      out.write("            <li><a href=\"/admin/booking_management.jsp\">Quản lý đặt phòng</a></li>\n");
      out.write("                ");
}else if(user.getIsAdmin() == 0 && user.getIsStaff() == 1){
      out.write("\n");
      out.write("            <li><a href=\"/admin/management.jsp\">Thống kê</a></li>\n");
      out.write("            <li><a href=\"/booking.jsp\">Đặt phòng</a></li>\n");
      out.write("            <li><a href=\"/admin/booking_management.jsp\">Quản lý đặt phòng</a></li>\n");
      out.write("                ");
}
      out.write("\n");
      out.write("        </ul>\n");
      out.write("    </div>\n");
      out.write("    <div style=\"display: flex; gap: 10px; align-items: center\">\n");
      out.write("        <p style=\"margin: 0px;\">Xin chào, <a href=\"/info.jsp\">");
      out.print(user.getFullname());
      out.write("</a></p>\n");
      out.write("        <a href=\"/logoutController\"><button class=\"btn btn-danger\"><i class='bx bx-log-out-circle'></i></button></a>\n");
      out.write("    </div>\n");
      out.write("</div>");
      out.write("\n");
      out.write("        ");
if(user.getIsStaff() == 1){
      out.write("\n");
      out.write("        ");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
  if(user.getIsStaff() == 0 && user.getIsAdmin() == 0){
        response.sendRedirect("/home.jsp");
    }
      out.write('\n');
      out.write("\n");
      out.write("        ");
}else{
      out.write("\n");
      out.write("        ");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
  if(user != null){
        if(user.getIsAdmin() == 1){
            response.sendRedirect("/admin/management.jsp");
        }else if(user.getIsStaff() == 1){
            response.sendRedirect("/admin/management.jsp");
        }
    }
      out.write('\n');
      out.write("\n");
      out.write("        ");
}
      out.write("\n");
      out.write("        <h2>Đặt phòng nhà nghỉ</h2>\n");
      out.write("        <h3 class=\"text-center\">Bảng giá</h3>\n");
      out.write("        <table class=\"table table-bordered table-striped\">\n");
      out.write("            <tr class=\"table-danger\">\n");
      out.write("                <th>STT</th>\n");
      out.write("                <th>Loại phòng</th>\n");
      out.write("                <th>Giá</th>\n");
      out.write("            </tr>\n");
      out.write("            ");
DAO dao = new DAO();
            CategoryDao cd = new CategoryDao();
            BookingDao bd = new BookingDao();
            RoomDao rd = new RoomDao();
            List<RoomCategory> listRoom = dao.getAllRoom();
            List<Category> listCategory = cd.getAll();
//            bd.updateStatus();
            for(Category cate : listCategory){
      out.write("\n");
      out.write("            <tr>\n");
      out.write("                <td>");
      out.print(cate.getIdcate());
      out.write("</td>\n");
      out.write("                <td>");
      out.print(cate.getCate());
      out.write("</td>\n");
      out.write("                <td>");
      out.print(Util.formatToVND(cate.getPrice()));
      out.write("</td>\n");
      out.write("            </tr>\n");
      out.write("            ");
}
      out.write("\n");
      out.write("        </table>\n");
      out.write("        <h3 class=\"text-center\">Booking</h3>\n");
      out.write("        <div class=\"bg-danger-subtle\" style=\"display: flex; justify-content: space-around; padding: 1rem 0px\">\n");
      out.write("            <h6 style=\"width: 120px\">Số phòng</h6>\n");
      out.write("            <h6 style=\"width: 120px\">Tình trạng thuê</h6>\n");
      out.write("            <h6 style=\"width: 120px\">Loại phòng</h6>\n");
      out.write("            <h6 style=\"width: 120px\">Ngày đặt</h6>\n");
      out.write("            <h6 style=\"width: 120px\">Ngày trả</h6>\n");
      out.write("            <h6 style=\"width: 120px\"></h6>\n");
      out.write("        </div>\n");
      out.write("        <div class=\"table list\">\n");
      out.write("            ");
for(RoomCategory rc : listRoom){
      out.write("\n");
      out.write("            <form class=\"item\" action=\"/bookingController\" method=\"post\" class=\"bookingForm\">\n");
      out.write("                <div style=\"display: flex; align-items: center; justify-content: space-around; padding: 20px 0; border-bottom: 1px solid rgba(0,0,0,0.3)\">\n");
      out.write("                    <div style=\"width: 120px\">\n");
      out.write("                        ");
      out.print(rc.getRoom());
      out.write("\n");
      out.write("                        <input type=\"hidden\" name=\"room\" value=\"");
      out.print(rc.getRoom());
      out.write("\">\n");
      out.write("                    </div>\n");
      out.write("                    ");
if(rc.getStatus() == 0){
      out.write("  \n");
      out.write("                    <div style=\"width: 120px\">\n");
      out.write("                        <input type=\"hidden\" name=\"status\" value=\"");
      out.print(rc.getStatus());
      out.write("\">  \n");
      out.write("                        Trống\n");
      out.write("                    </div>\n");
      out.write("                    ");
}else{
      out.write("\n");
      out.write("                    <div style=\"width: 120px\">\n");
      out.write("                        <input type=\"hidden\" name=\"status\" value=\"");
      out.print(rc.getStatus());
      out.write("\">\n");
      out.write("                        Được thuê\n");
      out.write("                    </div>\n");
      out.write("                    ");
}
      out.write("\n");
      out.write("                    <div style=\"width: 120px\">\n");
      out.write("                        ");
      out.print(rc.getCategory());
      out.write("\n");
      out.write("                        <input type=\"hidden\" name=\"category\" value=\"");
      out.print(rc.getCategory());
      out.write("\">\n");
      out.write("                    </div>\n");
      out.write("                    <div style=\"width: 120px\"><input type=\"date\" name=\"checkin\" required></div>\n");
      out.write("                    <div style=\"width: 120px\"><input type=\"date\" name=\"checkout\" required></div>\n");
      out.write("                    ");
if(rc.getStatus() == 0){
      out.write("  \n");
      out.write("                    <div style=\"width: 120px\"><input class=\"btn btn-primary\" type=\"submit\" value=\"Đặt phòng\"></div>\n");
      out.write("                    ");
}else{
      out.write("\n");
      out.write("                    <div style=\"width: 120px\"><input class=\"btn btn-primary\" type=\"submit\" value=\"Đặt phòng\" disabled></div>\n");
      out.write("                    ");
}
      out.write("\n");
      out.write("                </div>\n");
      out.write("            </form>\n");
      out.write("            ");
}
      out.write("\n");
      out.write("        </div>\n");
      out.write("        ");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("        <style>\n");
      out.write("            .pagination li{\n");
      out.write("                padding: 10px;\n");
      out.write("                border: 1px solid #000;\n");
      out.write("            }\n");
      out.write("            .active{\n");
      out.write("                background-color: #db2a34;\n");
      out.write("                color: white;\n");
      out.write("            }\n");
      out.write("        </style>\n");
      out.write("        <ul class=\"pagination\" style=\"list-style: none;display: flex; justify-content: center; gap: 10px;\">\n");
      out.write("            <li>first</li>\n");
      out.write("            <li>second</li>\n");
      out.write("            <li>third</li>\n");
      out.write("        </ul>\n");
      out.write("        <script>\n");
      out.write("            //pagination\n");
      out.write("            let thisPage = 1;\n");
      out.write("            let limit = 8;\n");
      out.write("            let list = document.querySelectorAll(\".list .item\");\n");
      out.write("            function loadItem() {\n");
      out.write("                let beginGet = limit * (thisPage - 1);\n");
      out.write("                let endGet = limit * thisPage - 1;\n");
      out.write("                list.forEach((item, key) => {\n");
      out.write("                    if (key >= beginGet && key <= endGet) {\n");
      out.write("                        item.style.display = \"\";\n");
      out.write("                    } else {\n");
      out.write("                        item.style.display = \"none\";\n");
      out.write("                    }\n");
      out.write("                });\n");
      out.write("                listPage();\n");
      out.write("            }\n");
      out.write("            loadItem();\n");
      out.write("            function listPage() {\n");
      out.write("                let max = Math.ceil(list.length / limit);\n");
      out.write("                document.querySelector(\".pagination\").innerHTML = '';\n");
      out.write("                if (thisPage !== 1) {\n");
      out.write("                    let prev = document.createElement(\"li\");\n");
      out.write("                    prev.innerHTML = '<span aria-hidden=\"true\">&laquo;</span>';\n");
      out.write("                    prev.setAttribute('onclick', 'changePage(' + (thisPage - 1) + ')');\n");
      out.write("                    document.querySelector('.pagination').appendChild(prev);\n");
      out.write("                }\n");
      out.write("                for (i = 1; i <= max; i++) {\n");
      out.write("                    let newPage = document.createElement(\"li\");\n");
      out.write("                    newPage.innerHTML = i;\n");
      out.write("                    if (i === thisPage) {\n");
      out.write("                        newPage.classList.add('active');\n");
      out.write("                    }\n");
      out.write("                    newPage.setAttribute('onclick', 'changePage(' + i + ')');\n");
      out.write("                    document.querySelector('.pagination').appendChild(newPage);\n");
      out.write("                }\n");
      out.write("                if (thisPage !== max) {\n");
      out.write("                    let next = document.createElement(\"li\");\n");
      out.write("                    next.innerHTML = '<span aria-hidden=\"true\">&raquo;</span>';\n");
      out.write("                    next.setAttribute('onclick', 'changePage(' + (thisPage + 1) + ')');\n");
      out.write("                    document.querySelector('.pagination').appendChild(next);\n");
      out.write("                }\n");
      out.write("            }\n");
      out.write("            function changePage(i) {\n");
      out.write("                thisPage = i;\n");
      out.write("                loadItem();\n");
      out.write("            }\n");
      out.write("        </script>\n");
      out.write("\n");
      out.write("<!--        <script>\n");
      out.write("            document.querySelectorAll(\".bookingForm\").forEach(form => {\n");
      out.write("                form.addEventListener(\"submit\", e => {\n");
      out.write("                    let checkinInput = form.querySelector('[name=\"checkin\"]').value;\n");
      out.write("                    let checkoutInput = form.querySelector('[name=\"checkout\"]').value;\n");
      out.write("                    let checkin = new Date(checkinInput);\n");
      out.write("                    let checkout = new Date(checkoutInput);\n");
      out.write("                    console.log(checkin);\n");
      out.write("                    console.log(checkout);\n");
      out.write("\n");
      out.write("                    const isDayValid = (date) => {\n");
      out.write("                        const current = new Date();\n");
      out.write("                        return (date.getFullYear() === current.getFullYear() && date.getMonth() === current.getMonth() && (date.getDate() === current.getDate() || date.getDate() === current.getDate() + 1 || date.getDate() === current.getDate() + 2));\n");
      out.write("                    };\n");
      out.write("\n");
      out.write("                    const isCheckoutValid = (checkin, checkout) => {\n");
      out.write("                        //let oneDay = 24 * 60 * 60 * 1000;\n");
      out.write("                        //let nextDay = new Date(checkin.getTime() + oneDay);\n");
      out.write("                        return checkout.getTime() >= checkin.getTime();\n");
      out.write("                    };\n");
      out.write("\n");
      out.write("                    if (!isDayValid(checkin) || !isCheckoutValid(checkin, checkout)) {\n");
      out.write("                        e.preventDefault();\n");
      out.write("                    }\n");
      out.write("                });\n");
      out.write("            });\n");
      out.write("        </script>-->\n");
      out.write("        ");
      if (_jspx_meth_c_if_0(_jspx_page_context))
        return;
      out.write("\n");
      out.write("        \n");
      out.write("        ");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("        ");
}
      out.write("\n");
      out.write("    </body>\n");
      out.write("</html>");
      out.write('\n');
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

  private boolean _jspx_meth_c_if_0(PageContext _jspx_page_context)
          throws Throwable {
    PageContext pageContext = _jspx_page_context;
    JspWriter out = _jspx_page_context.getOut();
    //  c:if
    org.apache.taglibs.standard.tag.rt.core.IfTag _jspx_th_c_if_0 = (org.apache.taglibs.standard.tag.rt.core.IfTag) _jspx_tagPool_c_if_test.get(org.apache.taglibs.standard.tag.rt.core.IfTag.class);
    _jspx_th_c_if_0.setPageContext(_jspx_page_context);
    _jspx_th_c_if_0.setParent(null);
    _jspx_th_c_if_0.setTest(((java.lang.Boolean) org.apache.jasper.runtime.PageContextImpl.evaluateExpression("${not empty nofty}", boolean.class, (PageContext)_jspx_page_context, null)).booleanValue());
    int _jspx_eval_c_if_0 = _jspx_th_c_if_0.doStartTag();
    if (_jspx_eval_c_if_0 != jakarta.servlet.jsp.tagext.Tag.SKIP_BODY) {
      do {
        out.write("\n");
        out.write("            <script>\n");
        out.write("            alert(\"");
        out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.evaluateExpression("${nofty}", java.lang.String.class, (PageContext)_jspx_page_context, null));
        out.write("\");\n");
        out.write("            </script>\n");
        out.write("        ");
        int evalDoAfterBody = _jspx_th_c_if_0.doAfterBody();
        if (evalDoAfterBody != jakarta.servlet.jsp.tagext.BodyTag.EVAL_BODY_AGAIN)
          break;
      } while (true);
    }
    if (_jspx_th_c_if_0.doEndTag() == jakarta.servlet.jsp.tagext.Tag.SKIP_PAGE) {
      _jspx_tagPool_c_if_test.reuse(_jspx_th_c_if_0);
      return true;
    }
    _jspx_tagPool_c_if_test.reuse(_jspx_th_c_if_0);
    return false;
  }
}
