import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			int date = sc.nextInt(), d, m, y;
			m = date / 1000000;
			d = (date / 10000) % 100;
			y = date % 10000;
			GregorianCalendar DOB = new GregorianCalendar(y, m-1, d);
			DOB.add(Calendar.DATE, 280);

			System.out.print((i + 1) + " ");
			if ((DOB.get(Calendar.MONTH)+1) < 10)
				System.out.print(0);
			System.out.print((DOB.get(Calendar.MONTH)+1) + "/");
			if (DOB.get(Calendar.DATE) < 10)
				System.out.print(0);
			System.out.println(DOB.get(Calendar.DATE) + "/"
					+ DOB.get(Calendar.YEAR) + " " + getZodiac(DOB));
		}
	}

	static String getZodiac(GregorianCalendar DOB) {
		switch (DOB.get(Calendar.MONTH)) {
		case Calendar.JANUARY:
			if (DOB.get(Calendar.DATE) < 21)
				return "capricorn";
			else {
				return "aquarius";
			}
		case Calendar.FEBRUARY:
			if (DOB.get(Calendar.DATE) < 20)
				return "aquarius";
			else {
				return "pisces";
			}
		case Calendar.MARCH:
			if (DOB.get(Calendar.DATE) < 21)
				return "pisces";
			else {
				return "aries";
			}
		case Calendar.APRIL:
			if (DOB.get(Calendar.DATE) < 21)
				return "aries";
			else {
				return "taurus";
			}
		case Calendar.MAY:
			if (DOB.get(Calendar.DATE) < 22)
				return "taurus";
			else {
				return "gemini";
			}
		case Calendar.JUNE:
			if (DOB.get(Calendar.DATE) < 22)
				return "gemini";
			else {
				return "cancer";
			}
		case Calendar.JULY:
			if (DOB.get(Calendar.DATE) < 23)
				return "cancer";
			else {
				return "leo";
			}
		case Calendar.AUGUST:
			if (DOB.get(Calendar.DATE) < 22)
				return "leo";
			else {
				return "virgo";
			}
		case Calendar.SEPTEMBER:
			if (DOB.get(Calendar.DATE) < 24)
				return "virgo";
			else {
				return "libra";
			}
		case Calendar.OCTOBER:
			if (DOB.get(Calendar.DATE) < 24)
				return "libra";
			else {
				return "scorpio";
			}
		case Calendar.NOVEMBER:
			if (DOB.get(Calendar.DATE) < 23)
				return "scorpio";
			else {
				return "sagittarius";
			}
		case Calendar.DECEMBER:
			if (DOB.get(Calendar.DATE) < 22)
				return "sagittarius";
			else {
				return "capricorn";
			}
		default:
			return "??";
		}
	}

}
