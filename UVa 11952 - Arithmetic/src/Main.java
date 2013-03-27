import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int tc, base, MAXBASE = 18;
		String a, b, s;
		BigInteger bia, bib, bis, bires;

		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		tc = sc.nextInt();
		while (tc-- > 0) {
			a = sc.next();
			sc.next();
			b = sc.next();
			sc.next();
			s = sc.next();

			if (a.matches("1+") && b.matches("1+") && s.matches("1+")
					&& a.length() + b.length() == s.length()) {
				pr.println(1);
				continue;
			}

			for (base = 2; base <= MAXBASE; base++) {
				try {
					bia = new BigInteger(a, base);
					bib = new BigInteger(b, base);
					bires = bia.add(bib);
					bis = new BigInteger(s, base);

					if (bis.equals(bires))
						break;
				} catch (NumberFormatException e) {
				}
			}

			if (base > MAXBASE)
				pr.println(0);
			else
				pr.println(base);
		}
		pr.flush();
	}
}
