// non-recursive-PASS
public class Solution {

	public static void main(String[] args) {
		Solution t = new Solution();
		for (int n = 4; n < 20; n++)
			System.out.println(t.totalNQueens(n));
	}

	public int totalNQueens(int n) {
		Counter counter = new Counter();
		nonRecursiveSearch(n, counter);
		return counter.value();
	}

	private void nonRecursiveSearch(int n, Counter counter) {
		int[] points = new int[n];
		int initVal = -n-n-n;
		for(int i=0; i<n; i++){
			points[i] = initVal;
		}
		
		int row = 0, col = 0;
		while (row < n) {

			while (col < n) {
				if (available(row, col, points)) {
					points[row] = col;
					col = 0;
					break;
				} else {
					col++;
				}
			}

			if (col >= n) {
				if (row == 0) {
					break;// end
				} else {
					row--;
					col = points[row] + 1;
					points[row] = initVal;
					continue;
				}
			}

			if (row == n-1) {
				counter.increase();
				col = points[row] + 1;
				points[row] = initVal;
			} else
				row++;
		}
	}

	private boolean available(int row, int col, int[] points) {
		for (int i = 0; i < points.length; i++) {
			if (col == points[i]
					|| (Math.abs(row - i) == Math.abs(col - points[i])))
				return false;
		}
		return true;
	}

	static class Counter {
		private int count;

		public void increase() {
			count++;
		}

		public void decrease() {
			count--;
		}

		public int value() {
			return count;
		}
	}
}

// dfs-recursive-PASS
class Solution2 {

	public static void main(String[] args) {
		Solution t = new Solution();
		for (int n = 1; n < 20; n++)
			System.out.println(t.totalNQueens(n));
	}
	private static final int InitVal = Integer.MIN_VALUE;
	public int totalNQueens(int n) {
		Counter counter = new Counter();
		int[] points = new int[n]; // 下标为行号，值为列号
		for(int i=0; i<n; i++)
			points[i] = InitVal;
		dfsSearch(0, n, points, counter);
		return counter.value();
	}

	private void dfsSearch(int row, int n, int[] points,
			Counter counter) {
		if (row >= n)
			counter.increase();
		else {
			for (int col = 0; col < n; col++) {
				if (available(row, col, points)) {
					points[row] = col;
					dfsSearch(row + 1, n, points, counter);
					points[row] = InitVal;
				}
			}
		}
	}

	private boolean available(int row, int col, int[] points) {
		for (int i = 0; i < points.length; i++) {
			if (col == points[i]
					|| (Math.abs(row - i) == Math.abs(col - points[i])))
				return false;
		}
		return true;
	}

	static class Counter {
		private int count;

		public void increase() {
			count++;
		}

		public void decrease() {
			count--;
		}

		public int value() {
			return count;
		}
	}
}
