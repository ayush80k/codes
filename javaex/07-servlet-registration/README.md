# Experiment 7: Servlet - User Registration
```
export TOMCAT=/path/to/apache-tomcat-10.x
mkdir -p webapp/WEB-INF/classes
javac -cp $TOMCAT/lib/servlet-api.jar -d webapp/WEB-INF/classes src/*.java
jar -cvf registration.war -C webapp .
cp registration.war $TOMCAT/webapps/
$TOMCAT/bin/startup.sh
```
Open: http://localhost:8080/registration/register.html
(For Tomcat 9, use `javax.servlet` imports.)
