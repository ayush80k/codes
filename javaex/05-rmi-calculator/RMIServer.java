import java.rmi.registry.*;

public class RMIServer {
    public static void main(String[] args) throws Exception {
        Registry reg = LocateRegistry.createRegistry(1099);
        reg.rebind("CalculatorService", new CalculatorImpl());
        System.out.println("RMI Server ready...");
    }
}
