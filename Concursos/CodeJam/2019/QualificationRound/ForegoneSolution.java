import java.math.BigInteger;
import java.util.Scanner;

public class ForegoneSolution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        BigInteger n, x, y;
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
                    String val = String.valueOf((long)Math.pow(10, j));
                    y = y.add(new BigInteger(val));
                    x = x.subtract(new BigInteger(val));
                }
            }
            System.out.println("Case #" + i + ": " + x + " " + y);
        }
    }
}
