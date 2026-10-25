<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<body>
<%
    String name = request.getParameter("name");
    int total = 0;
    for (int i = 1; i <= 5; i++)
        total += Integer.parseInt(request.getParameter("m" + i));
    double pct = total / 5.0;
    String grade;
    if (pct >= 90) grade = "O";
    else if (pct >= 80) grade = "A";
    else if (pct >= 70) grade = "B";
    else if (pct >= 60) grade = "C";
    else if (pct >= 40) grade = "D";
    else grade = "F (Fail)";
%>
<h2>Result for <%= name %></h2>
<p>Total: <%= total %> / 500</p>
<p>Percentage: <%= String.format("%.2f", pct) %>%</p>
<p>Grade: <b><%= grade %></b></p>
<a href="index.html">Back</a>
</body>
</html>
