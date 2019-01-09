import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class I {
    public static void main(String[] args) throws IOException {
        int T;
        String strNum;
        BigInteger k;
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(sc.readLine()); // leer el número de casos
        for (int i = 0; i < T; i++) {
            strNum = sc.readLine();
            k = new BigInteger(strNum);
            System.out.println(resolver(k));
        }
    }

    public static String resolver(BigInteger k) {
        String ans;
        BigInteger resultado;
        k = k.multiply(new BigInteger(Integer.toString(2)));
        k = k.multiply(new BigInteger(Integer.toString(4)));
        k = k.add(new BigInteger(Integer.toString(1)));
        resultado = sqrt(k);
        resultado = resultado.subtract(new BigInteger(Integer.toString(1)));
        if(resultado.remainder(new BigInteger(Integer.toString(2))).compareTo(new BigInteger("0")) == 0) {
            resultado = resultado.divide(new BigInteger(Integer.toString(2)));
            ans = resultado.toString();
        }
        else {
            ans = "-1";
        }
        return ans;
    }
    
    public static BigInteger sqrt(BigInteger x) {
        BigInteger div = BigInteger.ZERO.setBit(x.bitLength()/2);
        BigInteger div2 = div;
        // Loop until we hit the same value twice in a row, or wind
        // up alternating.
        for(;;) {
            BigInteger y = div.add(x.divide(div)).shiftRight(1);
            if (y.equals(div) || y.equals(div2)) return y;
            div2 = div;
            div = y;
        }
    }
}
