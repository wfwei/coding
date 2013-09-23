import java.util.Collections;
import java.util.PriorityQueue;

// not tested
public class Haffman {

	// 农夫钜木，费用是每块木板的长度，求最小费用。
	public int minCost(int cuts[]) {
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(10,
				Collections.reverseOrder());
		for (int i = 0; i < cuts.length; i++)
			pq.add(cuts[i]);
		int minCost = 0;
		while (pq.size() > 1) {
			int sumlen = pq.poll() + pq.poll();
			minCost += sumlen;
			pq.add(sumlen);
		}
		return minCost;
	}
}
