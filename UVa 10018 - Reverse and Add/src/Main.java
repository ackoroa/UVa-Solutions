import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		int TC = sc.nextInt();

		while (TC-- > 0) {
			String ns = sc.next();
			StringBuffer n = new StringBuffer(ns);

			BigInteger n1 = new BigInteger(n.toString()), n2;
			int count = 0;
			while (true) {
				n2 = new BigInteger(new StringBuffer(ns).reverse().toString());

				n1 = n1.add(n2);
				count++;

				ns = n1.toString();
				if (palin(ns.toCharArray())) {
					pr.println(count + " " + ns);
					break;
				}
			}
		}
		pr.close();
	}

	public static boolean palin(char n[]) {
		Stack<Character> checker = new Stack<Character>();
		int len = n.length, i;

		for (i = 0; i < len / 2; i++) {
			checker.push(n[i]);
		}
		if (len % 2 == 1)
			checker.push(n[i]);
		for (; i < len; i++) {
			if (!checker.pop().equals(new Character(n[i])))
				return false;
		}
		return true;
	}
}
