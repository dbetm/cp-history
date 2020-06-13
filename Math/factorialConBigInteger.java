import java.util.Scanner;
import java.math.BigInteger;

class factorialConBigInteger {
    public static void main(String[] args) {
        BigInteger factorial = BigInteger.ONE;
        for (int i = 2;i <= 200000; i++) {
            factorial = factorial.multiply(BigInteger.valueOf(i));
            System.out.println(i);
        }
        System.out.println(factorial);
    }
}
