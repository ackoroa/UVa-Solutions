import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int TC = sc.nextInt();
		BigDecimal sum, n;

		while (TC-- > 0) {
			sum = BigDecimal.ZERO;

			while (true) {
				n = new BigDecimal(sc.next());
				if (n.equals(BigDecimal.ZERO))
					break;

				sum = sum.add(n);
			}

			if (sum.compareTo(BigDecimal.ZERO) == 0) {
				pr.println("0");
			} else {
				sum = sum.stripTrailingZeros();
				pr.println(sum.toPlainString());
			}
		}
		pr.close();
	}

}
