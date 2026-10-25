import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        try (Socket s = new Socket("localhost", 5000);
             BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
             PrintWriter out = new PrintWriter(s.getOutputStream(), true);
             BufferedReader kb = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.println("Connected to server. Type 'bye' to exit.");
            String msg;
            while (true) {
                System.out.print("Client: ");
                msg = kb.readLine();
                out.println(msg);
                if (msg.equalsIgnoreCase("bye")) break;
                String reply = in.readLine();
                if (reply == null) break;
                System.out.println("Server: " + reply);
            }
        }
    }
}
