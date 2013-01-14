import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger n, a, ai, sum;

		while (sc.hasNext()) {
			n = new BigInteger(sc.next());
			a = new BigInteger(sc.next());

			sum = BigInteger.ZERO;
			int lim = n.intValue();
			for (int i = 1; i <= lim; i++) {
				ai = BigInteger.ONE;
				for (int j = 0; j < i; j++) {
					ai = ai.multiply(a);
				}
				sum = sum.add(ai.multiply(new BigInteger(Integer.toString(i))));
			}

			System.out.println(sum);
		}
	}

}
