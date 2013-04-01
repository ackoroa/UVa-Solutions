import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	private static final String VERB = "(hate|love|know|like)s*";
	private static final String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
	private static final String ARTICLE = "(a|the)";
	private static final String ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN
			+ ")";
	private static final String ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
	private static final String ACTION = ACTIVE_LIST + " " + VERB + " "
			+ ACTIVE_LIST;
	private static final String STATEMENT = ACTION + "( , " + ACTION + ")*";

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		String s;
		while (sc.hasNext()) {
			s = sc.nextLine();
			if (s.matches(STATEMENT)) {
				pr.println("YES I WILL");
			} else {
				pr.println("NO I WON'T");
			}
		}
		pr.flush();
	}
}
