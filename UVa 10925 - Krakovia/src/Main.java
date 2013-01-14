import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, f, count = 0;
		BigInteger item, sum;

		while (true) {
			count++;

			n = sc.nextInt();
			f = sc.nextInt();
			if (n == 0 && f == 0)
				break;

			sum = BigInteger.ZERO;
			for (int i = 0; i < n; i++) {
				sum = sum.add(new BigInteger(sc.next()));
			}

			System.out.println("Bill #" + count + " costs " + sum
					+ ": each friend should pay "
					+ sum.divide(new BigInteger(Integer.toString(f))) + "\n");
		}
	}
}
