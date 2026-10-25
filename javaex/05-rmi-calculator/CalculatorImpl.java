import java.rmi.*;
import java.rmi.server.*;

public class CalculatorImpl extends UnicastRemoteObject implements Calculator {
    public CalculatorImpl() throws RemoteException { super(); }

    public double compute(double a, double b, char op) throws RemoteException {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw new RemoteException("Division by zero");
                return a / b;
            default: throw new RemoteException("Invalid operator: " + op);
        }
    }
}
