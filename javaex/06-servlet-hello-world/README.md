# Experiment 6: Servlet - Hello World
Uses Tomcat 10+ (`jakarta.servlet`). For Tomcat 9 or older, replace `jakarta.` with `javax.` in imports.

Set `TOMCAT` to your Tomcat folder, then:
```
export TOMCAT=/path/to/apache-tomcat-10.x      # Windows: set TOMCAT=C:\path\to\tomcat
mkdir -p webapp/WEB-INF/classes
javac -cp $TOMCAT/lib/servlet-api.jar -d webapp/WEB-INF/classes src/*.java
jar -cvf hello.war -C webapp .
cp hello.war $TOMCAT/webapps/
$TOMCAT/bin/startup.sh        # Windows: startup.bat
```
Open: http://localhost:8080/hello/hello
