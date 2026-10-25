import java.rmi.registry.*;
import java.util.Scanner;

public class RMIClient {
    public static void main(String[] args) throws Exception {
        Registry reg = LocateRegistry.getRegistry("localhost", 1099);
        Calculator calc = (Calculator) reg.lookup("CalculatorService");
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first operand: ");
        double a = sc.nextDouble();
        System.out.print("Enter operator (+ - * /): ");
        char op = sc.next().charAt(0);
        System.out.print("Enter second operand: ");
        double b = sc.nextDouble();
        System.out.println("Result = " + calc.compute(a, b, op));
    }
}
