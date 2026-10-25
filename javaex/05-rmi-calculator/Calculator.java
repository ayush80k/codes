import java.rmi.*;

public interface Calculator extends Remote {
    double compute(double a, double b, char operator) throws RemoteException;
}
