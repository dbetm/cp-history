import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collections;
// Para correr cambiar el nombre del archivo y clase.
// https://omegaup.com/arena/problem/Sumas-Veleanas#problems
public class 15_SumasVeleanas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useDelimiter("\n");
        int n = sc.nextInt();
        String A = sc.next();
        String B = sc.next();
        String a[] = A.split("\\s+");
        String b[] = B.split("\\s+");
        // sorting
        Arrays.sort(a);
        //Arrays.sort(new String(b), Collections.reverseOrder());
        Arrays.sort(b, Collections.reverseOrder());
        A = Arrays.toString(a)
            .replace(",", "")  //remove the commas
            .replace("[", "")  //remove the right bracket
            .replace("]", "")  //remove the left bracket
            .replace(" ", "");
        B = Arrays.toString(b)
            .replace(",", "")  //remove the commas
            .replace("[", "")  //remove the right bracket
            .replace("]", "")  //remove the left bracket
            .replace(" ", "");
        BigInteger bi = new BigInteger(A);
        bi = bi.add(new BigInteger(B));
        System.out.println(bi);
        sc.close();
    }
}
