import java.math.BigInteger;
import java.util.Scanner;
// For test 1, accepted
// For test 2, accepted
// For test 3, accepted
// Test 2 -> TLE
public class ForegoneSolution {
    // Constructive solution
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        BigInteger n, x, y, rr;
        String aux;
        int len;
        // BigInteger f = new BigInteger("1");
        for (int i = 1; i <= t; i++) {
            aux = sc.next();
            x = new BigInteger(aux);
            y = new BigInteger("0");
            len = aux.length();
            for (int j = 0; j < len; j++) {
                if(aux.charAt(len-1-j) == '4') {
                    rr = new BigInteger(String.valueOf(10));
                    rr = rr.pow(j);
                    y = y.add(rr);
                    x = x.subtract(rr);
                }
            }
            System.out.println("Case #" + i + ": " + x + " " + y);
        }
    }
}
