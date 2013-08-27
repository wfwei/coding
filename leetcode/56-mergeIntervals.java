import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Solution {
	public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ArrayList<Interval> res = new ArrayList<Interval>();
    	Collections.sort(intervals, new Comparator<Interval>() {
			@Override
			public int compare(Interval o1, Interval o2) {
				if (o2.start > o1.start)
					return -1;
				else
					return (o2.start == o1.start) ? 0 : 1;
			}
		});

		for (int i = 0; i < intervals.size();) {
			int s = intervals.get(i).start;
			int e = intervals.get(i).end;
			while ((++i) < intervals.size()) {
				if (intervals.get(i).start <= e) {
                    if(intervals.get(i).end>e)
					    e = intervals.get(i).end;
				} else
					break;
			}
			res.add(new Interval(s, e));
		}

		return res;
	}

	static class Interval {
		int start;
		int end;

		Interval() {
			start = 0;
			end = 0;
		}

		Interval(int s, int e) {
			start = s;
			end = e;
		}
	}
}
