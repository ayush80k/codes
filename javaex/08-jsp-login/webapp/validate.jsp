<%@ page contentType="text/html;charset=UTF-8" import="java.sql.*" %>
<html>
<body>
<%
    String user = request.getParameter("username");
    String pass = request.getParameter("password");
    String mode = request.getParameter("mode");
    boolean valid = false;

    if ("static".equals(mode)) {
        // Static: hard-coded credentials
        valid = "admin".equals(user) && "admin123".equals(pass);
    } else {
        // Dynamic: database (edit URL/USER/PASS)
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/college", "root", "root");
            PreparedStatement ps = con.prepareStatement(
                "SELECT * FROM users WHERE username=? AND password=?");
            ps.setString(1, user);
            ps.setString(2, pass);
            ResultSet rs = ps.executeQuery();
            valid = rs.next();
            con.close();
        } catch (Exception e) {
            out.println("<p style='color:red'>DB error: " + e.getMessage() + "</p>");
        }
    }

    if (valid) {
        out.println("<h2>Welcome, " + user + "! Login successful.</h2>");
    } else {
        out.println("<h2 style='color:red'>Invalid username or password.</h2>");
        out.println("<a href='login.jsp'>Try again</a>");
    }
%>
</body>
</html>
