# Experiment 11: Case Study - Enterprise Java Beans
EJB needs a Jakarta EE server (**not plain Tomcat**): WildFly, GlassFish/Payara, or Apache TomEE.

Theory points for the write-up: types of EJB - Session (Stateless, Stateful, Singleton), Message-Driven; services - transactions, security, concurrency, remote access.

Build (Jakarta EE API jar, e.g. from `$SERVER/modules` or Maven Central `jakarta.jakartaee-api`):
```
mkdir -p webapp/WEB-INF/classes
javac -cp jakartaee-api.jar -d webapp/WEB-INF/classes src/*.java
jar -cvf ejbdemo.war -C webapp .
```
Deploy `ejbdemo.war` to the server's deployments folder (WildFly: `standalone/deployments/`; GlassFish: `asadmin deploy ejbdemo.war`).

Open: http://localhost:8080/ejbdemo/calc?a=20&b=4
