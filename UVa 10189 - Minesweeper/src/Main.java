import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int[][] minefield;
	static List<Pair<Integer, Integer>> mines;

	public static void main(String[] args) {
		int n = -1, m = -1, i, j;
		Scanner sc = new Scanner(System.in);
		String line;
		int count = 0;

		while(true) {
			count ++;
			n = sc.nextInt();
			m = sc.nextInt();

			if(n==0 && m==0) break;
			
			minefield = new int[n][m];
			mines = new LinkedList<Pair<Integer, Integer>>();

			for (i = 0; i < n; i++) {
				line = sc.next();
				
				for (j = 0; j < m; j++) {
					switch (line.charAt(j)) {
					case '*':
						minefield[i][j] = -1;
						mines.add(new Pair<Integer, Integer>(i, j));
						break;
					case '.':
						minefield[i][j] = 0;
						break;
					default:
						System.exit(1);
					}
				}
			}
			
			for (Pair<Integer, Integer> mine : mines) {
				int y = mine.getL(), x = mine.getR();

				if (x > 0 && y > 0 && minefield[y - 1][x - 1] != -1)
					minefield[y - 1][x - 1]++;
				if (x > 0 && minefield[y][x-1] != -1)
					minefield[y][x-1]++;
				if (x > 0 && y < n-1 && minefield[y + 1][x - 1] != -1)
					minefield[y + 1][x - 1]++;
				if (y > 0 && minefield[y - 1][x] != -1)
					minefield[y - 1][x]++;
				if (y < n-1 && minefield[y + 1][x] != -1)
					minefield[y + 1][x]++;
				if (x < m-1 && y > 0 && minefield[y - 1][x + 1] != -1)
					minefield[y - 1][x + 1]++;
				if (x < m-1 && minefield[y][x + 1] != -1)
					minefield[y][x + 1]++;
				if (x < m-1 && y < n-1 && minefield[y + 1][x + 1] != -1)
					minefield[y + 1][x + 1]++;
			}
			
			if(count != 1) System.out.println();
			System.out.println("Field #" + count + ":");
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(minefield[i][j]>=0) System.out.print(minefield[i][j]);
					else System.out.print("*");
				}
				System.out.println();
			}
		}

	}

}

class Pair<L, R> {
	private L l;
	private R r;

	public Pair(L l, R r) {
		this.l = l;
		this.r = r;
	}

	public L getL() {
		return l;
	}

	public R getR() {
		return r;
	}

	public void setL(L l) {
		this.l = l;
	}

	public void setR(R r) {
		this.r = r;
	}
}
