public class Solution {

	public ArrayList<Integer> spiralOrder(int[][] matrix) {
		// Start typing your Java solution below
		// DO NOT write main() function
		int m = matrix.length, n = matrix.length > 0 ? matrix[0].length : 0;
		ArrayList<Integer> res = new ArrayList<Integer>();

		int si = 0, ei = m - 1, sj = 0, ej = n - 1;
		while (si <= ei && sj <= ej) {
			spiralOrder(matrix, si, sj, ei, ej, res);
			si++; sj++;
			ei--;
			ej--;
		}

		return res;

	}

	private void spiralOrder(int[][] matrix, int si, int sj, int ei, int ej,
			ArrayList<Integer> res) {

		for (int i = si, j = sj; j <= ej; j++)
			res.add(matrix[i][j]);

		for (int i = si + 1, j = ej; i <= ei; i++)
			res.add(matrix[i][j]);

		for (int i = ei, j = ej-1; i>si && j >= sj; j--)
			res.add(matrix[i][j]);

		for (int i = ei-1, j = sj; j<ej && i > si; i--)
			res.add(matrix[i][j]);
	}

	public static void main(String[] args) {
		Solution t = new Solution();
		int[][] matrix = { { 3 , 2 } };
//		int[][] matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
		System.out.println(t.spiralOrder(matrix));
	}
}

