import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		BigInteger num, denum, gcd;
		int TC;
		TC = sc.nextInt();

		while (TC-- > 0) {
			num = new BigInteger(sc.next());
			sc.next();
			denum = new BigInteger(sc.next());

			gcd = num.gcd(denum);

			num = num.divide(gcd);
			denum = denum.divide(gcd);

			pr.println(num + " / " + denum);
		}
		pr.close();
	}

}
