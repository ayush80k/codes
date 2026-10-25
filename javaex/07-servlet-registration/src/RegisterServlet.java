import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.*;

@WebServlet("/register")
public class RegisterServlet extends HttpServlet {
    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<html><body>");
        out.println("<h2>Registration Successful</h2>");
        out.println("Name: " + req.getParameter("name") + "<br>");
        out.println("Email: " + req.getParameter("email") + "<br>");
        out.println("Gender: " + req.getParameter("gender") + "<br>");
        out.println("City: " + req.getParameter("city") + "<br>");
        out.println("</body></html>");
    }
}
