import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int n, d, m, y;
		Scanner sc = new Scanner(System.in);

		while (true) {
			n = sc.nextInt();
			d = sc.nextInt();
			m = sc.nextInt();
			y = sc.nextInt();

			if (n == 0 && d == 0 && m == 0 && y == 0)
				break;

			GregorianCalendar cal = new GregorianCalendar(y, m-1, d);

			cal.add(Calendar.DATE, n);

			System.out.println(cal.get(Calendar.DATE) + " "
					+ (cal.get(Calendar.MONTH)+1) + " "
					+ cal.get(Calendar.YEAR));
		}
	}

}
