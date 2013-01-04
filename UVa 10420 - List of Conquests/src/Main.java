import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) {
		Map<String, Integer> logbook = new TreeMap<String, Integer>();
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		for (int i = n; i > 0; i--) {
			String country = sc.next();

			if (logbook.containsKey(country)) {
				logbook.put(country, logbook.get(country) + 1);
			} else {
				logbook.put(country, 1);
			}

			sc.nextLine();
		}
		sc.close();

		Iterator<Entry<String, Integer>> logIter = logbook.entrySet().iterator();
		
		while (logIter.hasNext()) {
			Entry<String, Integer> ent = logIter.next();
			System.out.println(ent.getKey() + " " + ent.getValue());
		}

	}
}
