import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        try (ServerSocket ss = new ServerSocket(5000)) {
            System.out.println("Server waiting for client on port 5000...");
            try (Socket s = ss.accept();
                 BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
                 PrintWriter out = new PrintWriter(s.getOutputStream(), true);
                 BufferedReader kb = new BufferedReader(new InputStreamReader(System.in))) {
                System.out.println("Client connected: " + s.getInetAddress());
                String msg;
                while ((msg = in.readLine()) != null) {
                    System.out.println("Client: " + msg);
                    if (msg.equalsIgnoreCase("bye")) break;
                    System.out.print("Server: ");
                    out.println(kb.readLine());
                }
            }
            System.out.println("Connection closed.");
        }
    }
}
