# Experiment 8: JSP Login (static & dynamic)
- Static login: `admin` / `admin123`
- Dynamic login: `student` / `pass123` (from MySQL)

Steps:
1. `mysql -u root -p < setup.sql`
2. Copy the MySQL Connector/J jar into `webapp/WEB-INF/lib/`
3. Edit DB user/password in `webapp/validate.jsp`
4. Build and deploy:
```
jar -cvf login.war -C webapp .
cp login.war /path/to/apache-tomcat-10.x/webapps/
/path/to/apache-tomcat-10.x/bin/startup.sh
```
Open: http://localhost:8080/login/login.jsp
