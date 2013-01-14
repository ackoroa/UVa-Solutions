import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		int TC;
		BigInteger n1,n2,sum;
		StringBuffer sb;
		Scanner sc = new Scanner(System.in);
		
		TC = sc.nextInt();
		
		while(TC-- > 0){
			sb = new StringBuffer(sc.next());
			n1 = new BigInteger(sb.reverse().toString());
			sb = new StringBuffer(sc.next());
			n2 = new BigInteger(sb.reverse().toString());
			
			sum = n1.add(n2);
			sb = new StringBuffer(sum.toString()).reverse();
			sum = new BigInteger(sb.toString());
			
			System.out.println(sum);
		}
	}

}
