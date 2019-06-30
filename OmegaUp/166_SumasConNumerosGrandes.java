import java.util.Scanner;
import java.math.BigInteger;
// https://omegaup.com/arena/problem/sumas-con-numeros-grandes#problems
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        BigInteger bi = new BigInteger(a);
        bi = bi.add(new BigInteger(b));
        System.out.println(bi);
        sc.close();
    }
}
