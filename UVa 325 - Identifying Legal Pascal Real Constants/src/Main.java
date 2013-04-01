import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		String s;
		while (!(s = sc.next()).equals("*")) {
			if(s.matches("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)"))
				pr.println(s + " is legal.");
			else
				pr.println(s + " is illegal.");
		}
		pr.flush();
	}
}
