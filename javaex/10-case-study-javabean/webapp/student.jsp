<%@ page contentType="text/html;charset=UTF-8" %>
<jsp:useBean id="stu" class="StudentBean" scope="request" />
<jsp:setProperty name="stu" property="rollNo" value="101" />
<jsp:setProperty name="stu" property="name" value="Riya" />
<jsp:setProperty name="stu" property="marks" value="88.5" />
<html>
<body>
<h2>Student (JavaBean in JSP)</h2>
Roll No: <jsp:getProperty name="stu" property="rollNo" /><br>
Name: <jsp:getProperty name="stu" property="name" /><br>
Marks: <jsp:getProperty name="stu" property="marks" />
</body>
</html>
