import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		int n, cC = 0, lC;
		GregorianCalendar cDate, lDate;
		while (true) {
			n = sc.nextInt();
			if (n == 0)
				break;

			int sum = 0, count = 0;
			cDate = new GregorianCalendar(0, 0, 0);
			for (int i = 0; i < n; i++) {
				int y, m, d;
				
				lDate = cDate;
				lC = cC;
				
				d = sc.nextInt();
				m = sc.nextInt() - 1;
				y = sc.nextInt();
				cC = sc.nextInt();

				cDate = new GregorianCalendar(y, m, d);
				lDate.add(Calendar.DATE, 1);
				if(cDate.equals(lDate)){
					sum += cC-lC;
					count++;
				}
			}
			pr.println(count + " " + sum);
		}
		pr.close();

	}

}
