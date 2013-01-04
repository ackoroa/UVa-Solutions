import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Map<List<Integer>, List<String>> map = new HashMap<List<Integer>, List<String>>();
		Scanner sc = new Scanner(System.in);
		PriorityQueue<String> outputQueue = new PriorityQueue<String>();

		while (true) {
			String word = sc.next();
			if (word.equals("#"))
				break;

			List<Integer> alphaFreq = new ArrayList<Integer>(
					Collections.nCopies(26, 0));

			for (int i = 0; i < word.length(); i++) {
				int key = (int) Character.toLowerCase(word.charAt(i)) - 97;

				alphaFreq.set(key, alphaFreq.get(key) + 1);
			}

			if (!map.containsKey(alphaFreq))
				map.put(alphaFreq, new ArrayList<String>());
			map.get(alphaFreq).add(word);
		}
		
		for(List<String> e : map.values()){
			if(e.size() == 1) outputQueue.add(e.get(0));
		}
		
		while(!outputQueue.isEmpty()){
			System.out.println(outputQueue.poll());
		}
		
	}
}
