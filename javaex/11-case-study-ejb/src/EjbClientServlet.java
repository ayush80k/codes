import jakarta.ejb.EJB;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.*;

@WebServlet("/calc")
public class EjbClientServlet extends HttpServlet {
    @EJB
    private CalculatorBean calc;

    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
        int a = Integer.parseInt(req.getParameter("a") == null ? "10" : req.getParameter("a"));
        int b = Integer.parseInt(req.getParameter("b") == null ? "5" : req.getParameter("b"));
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        out.println("<html><body><h2>EJB Calculator</h2>");
        out.println(a + " + " + b + " = " + calc.add(a, b) + "<br>");
        out.println(a + " - " + b + " = " + calc.subtract(a, b) + "<br>");
        out.println(a + " * " + b + " = " + calc.multiply(a, b) + "<br>");
        out.println(a + " / " + b + " = " + calc.divide(a, b) + "<br>");
        out.println("</body></html>");
    }
}
