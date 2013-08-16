import java.util.HashMap;

public class Solution {

	public ArrayList<Integer> findSubstring(String S, String[] L) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ArrayList<Integer> result = new ArrayList<Integer>();
		HashMap<String, Integer> lmap = new HashMap<String, Integer>(), rmap = new HashMap<String, Integer>();
		for (String word : L) {
			Integer count = lmap.get(word);
			if (count == null)
				count = 1;
			else
				count += 1;
			lmap.put(word, count);
		}

		int s, e, wlen = L.length > 0 ? L[0].length() : 0;
		int wcount = 0;
		for (s = 0, e = 0; e + wlen <= S.length();) {
			String cur = S.substring(e, e + wlen);
			Integer lcnt = lmap.get(cur);
			if (lcnt != null) {
				Integer rcnt = rmap.get(cur);
				if (rcnt == lcnt) {
					do {
						String next = S.substring(s, s + wlen);
						if (next.equals(cur)) {
							break;
						} else {
							Integer count = rmap.get(next);
							if (count > 1)
								rmap.put(next, count - 1);
							else
								rmap.remove(next);
							s += wlen;
							wcount--;
						}
					} while (true);
					s += wlen;
					e += wlen;
				} else {
					if (rcnt == null)
						rcnt = 1;
					else
						rcnt += 1;
					rmap.put(cur, rcnt);
					wcount++;
					e += wlen;
					if (wcount == L.length) {
						// found one match
						result.add(s);
						s++;
						e = s;
						rmap.clear();
						wcount = 0;
					}
				}
			} else {
				s ++;
				e = s;
				rmap.clear();
				wcount=0;
			}
		}
		return result;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Solution sol = new Solution();
		String str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
		String[] L = { "fooo","barr","wing","ding","wing"};
		System.out.print(sol.findSubstring(str, L));
	}
}
