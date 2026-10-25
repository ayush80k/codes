import java.sql.*;

public class JdbcDemo {
    // CHANGE THESE to match your MySQL setup
    static final String URL = "jdbc:mysql://localhost:3306/college";
    static final String USER = "root";
    static final String PASS = "root";

    public static void main(String[] args) {
        try (Connection con = DriverManager.getConnection(URL, USER, PASS)) {
            System.out.println("Connected to database.");

            try (Statement st = con.createStatement()) {
                st.executeUpdate("CREATE TABLE IF NOT EXISTS student("
                        + "id INT PRIMARY KEY, name VARCHAR(50), marks INT)");
            }

            // INSERT
            String ins = "INSERT INTO student VALUES(?,?,?) ON DUPLICATE KEY UPDATE name=VALUES(name), marks=VALUES(marks)";
            try (PreparedStatement ps = con.prepareStatement(ins)) {
                Object[][] rows = {{1, "Amit", 78}, {2, "Riya", 91}, {3, "Karan", 64}};
                for (Object[] r : rows) {
                    ps.setInt(1, (Integer) r[0]);
                    ps.setString(2, (String) r[1]);
                    ps.setInt(3, (Integer) r[2]);
                    ps.executeUpdate();
                }
                System.out.println("Records inserted.");
            }
            display(con, "After INSERT");

            // UPDATE
            try (PreparedStatement ps = con.prepareStatement("UPDATE student SET marks=? WHERE id=?")) {
                ps.setInt(1, 85); ps.setInt(2, 3);
                System.out.println(ps.executeUpdate() + " row updated.");
            }
            display(con, "After UPDATE");

            // DELETE
            try (PreparedStatement ps = con.prepareStatement("DELETE FROM student WHERE id=?")) {
                ps.setInt(1, 2);
                System.out.println(ps.executeUpdate() + " row deleted.");
            }
            display(con, "After DELETE");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    static void display(Connection con, String title) throws SQLException {
        System.out.println("\n--- " + title + " ---");
        try (Statement st = con.createStatement();
             ResultSet rs = st.executeQuery("SELECT * FROM student ORDER BY id")) {
            while (rs.next())
                System.out.println(rs.getInt(1) + "\t" + rs.getString(2) + "\t" + rs.getInt(3));
        }
    }
}
