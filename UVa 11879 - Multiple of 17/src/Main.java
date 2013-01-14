import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger n;
		int ans;

		while (true) {
			n = new BigInteger(sc.next());
			if (n.equals(BigInteger.ZERO))
				break;
			
			if (n.mod(new BigInteger("17")).equals(BigInteger.ZERO))
				ans = 1;
			else
				ans = 0;

			System.out.println(ans);
		}
	}

}
