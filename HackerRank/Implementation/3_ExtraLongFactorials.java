import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class ExtraLongFactorials {
    public static void main(String[] args) throws IOException {
        int n;
        BigInteger ans;
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(sc.readLine());
        ans = new BigInteger(Integer.toString(n));
        for (int i = n-1; i > 1; i--) {
            ans = ans.multiply(new BigInteger(Integer.toString(i)));
        }
        System.out.println(ans.toString());
    }
}
