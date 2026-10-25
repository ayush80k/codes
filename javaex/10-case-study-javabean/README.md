# Experiment 10: Case Study - Java Bean
**Part A - plain Java:**
```
cd src
javac *.java
java TestBean
```
**Part B - use the bean in JSP (Tomcat):** note: bean class must be in a package for JSP on newer Tomcat; if you get an error, add `package beans;` to `StudentBean.java` and use `class="beans.StudentBean"`.
```
mkdir -p webapp/WEB-INF/classes
javac -d webapp/WEB-INF/classes src/StudentBean.java
jar -cvf bean.war -C webapp .
cp bean.war /path/to/apache-tomcat-10.x/webapps/
```
Open: http://localhost:8080/bean/student.jsp
