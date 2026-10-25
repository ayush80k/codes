# Experiment 3: JDBC Application (MySQL)
1. Install MySQL and run: `mysql -u root -p < setup.sql`
2. Download MySQL Connector/J jar (e.g. `mysql-connector-j-8.x.jar`) into this folder.
3. Edit `URL`, `USER`, `PASS` in `JdbcDemo.java`.
4. Run:
```
javac JdbcDemo.java
# Linux/Mac
java -cp .:mysql-connector-j-8.x.jar JdbcDemo
# Windows
java -cp .;mysql-connector-j-8.x.jar JdbcDemo
```
