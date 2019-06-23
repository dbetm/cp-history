import java.util.Scanner;
import java.math.BigInteger;
// https://omegaup.com/arena/problem/ptwo#problems
// Para generar el .class cambiar el nombre del archivo
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useDelimiter("\n");
        int n = sc.nextInt();

        BigInteger bi = new BigInteger("2");
        bi = bi.pow(n);
        System.out.println(bi);
        sc.close();
    }
}
