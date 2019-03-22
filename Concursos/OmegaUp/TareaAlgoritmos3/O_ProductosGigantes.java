import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String x = sc.next();
        String y = sc.next();

        BigInteger X = new BigInteger(x);
        BigInteger Y = new BigInteger(y);

        System.out.println(X.multiply(Y));

    }
}
