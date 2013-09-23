
package mine.coding;

import java.util.ArrayList;

public class Main {

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

		public String toString() {
			return String.format("{%s, %s}", start, end);
		}
	}

	
	public ArrayList<Interval> insert(ArrayList<Interval> intervals,
			Interval newInterval) {
		
		ArrayList<Interval> res = new ArrayList<Interval>();
		boolean inserted = false;
		for(int i=0; i<intervals.size(); i++){
			
			if(intervals.get(i).start > newInterval.end){
				res.add(newInterval);
				for(int j=i; j<intervals.size(); j++)
					res.add(intervals.get(j));
				inserted = true;
				break;
			}
			
			if(intervals.get(i).end < newInterval.start){
				res.add(intervals.get(i));
			}else{
				if(intervals.get(i).start<newInterval.start)
					newInterval.start = intervals.get(i).start;
				if(intervals.get(i).end > newInterval.end)
					newInterval.end = intervals.get(i).end;
			}
		}
		
		if(!inserted)
			res.add(newInterval);
		return res;
	}
	
	
	// TLE
	public ArrayList<Interval> insert2(ArrayList<Interval> intervals,
			Interval newInterval) {

		int s = 0, e = intervals.size() - 1;
		
		while(s<=e && intervals.get(s).start<newInterval.start){
			s++;
		}
		s -= 1;
		
		if(s<0){
			intervals.add(0, newInterval);
			s++; e++;
		}else if(s==e){
			intervals.add(newInterval);
			e++;
		}else{
			if(intervals.get(s).end<=newInterval.start){
				intervals.add(s+1, newInterval);
				e++;
			}else{
				if(intervals.get(s).end<newInterval.end)
					intervals.get(s).end = newInterval.end;
				else
					return intervals;
			}
		}
		
		while(s<e && intervals.get(s).end>=intervals.get(s+1).start){
			if(intervals.get(s).end < intervals.get(s+1).end)
				intervals.get(s).end = intervals.get(s+1).end;
			intervals.remove(s+1);
			e--;
		}

		return intervals;
	}


	public static void main(String[] args) {
		ArrayList<Interval> intervals = new ArrayList<Interval>();
		intervals.add(new Interval(2, 5));
		 intervals.add(new Interval(6,9));
		Main sol = new Main();
		intervals = sol.insert(intervals, new Interval(0,10));
		for (Interval interval : intervals) {
			System.out.print(interval);
		}
	}

}
