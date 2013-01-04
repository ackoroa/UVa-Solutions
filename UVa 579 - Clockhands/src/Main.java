import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
			String time = sc.next();
			StringTokenizer st = new StringTokenizer(time, ":");

			int hour = Integer.parseInt(st.nextToken());
			int mins = Integer.parseInt(st.nextToken());
			if (hour == 0 && mins == 0)
				break;

			double angle = Math.abs(0.5 * (60 * hour - 11 * mins));
			if(angle>180) angle = 360 - angle;

			System.out.printf("%.3f\n", angle);
		}
	}

}
