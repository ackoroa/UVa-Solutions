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
		Scanner ssc;
		String s;
		
		while(sc.hasNext()){
			s = sc.nextLine();
			ssc = new Scanner(s);
			
			while(ssc.hasNext()){
				s = ssc.next();
				pr.print(new StringBuffer(s).reverse().toString());
				if(ssc.hasNext()) pr.print(" ");
			}
			pr.println();
		}
		pr.flush();
	}

}
