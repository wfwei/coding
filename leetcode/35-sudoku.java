public class Solution {
	
	// PASS leetcode#36
	// 只判断当前局面是否合法，不管是否可解
	public boolean isValidSudoku(char[][] board) {
		for (int i = 0; i < board.length; i++) {
			int[] rows = new int[10];// initialized to be zeros
			int[] cols = new int[10];
			for(int j=0; j<board.length; j++){
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					if(rows[num]>0)
						return false;
					else
						rows[num]++;
				}
				if (board[j][i] != '.') {
					int num = board[j][i] - '0';
					if(cols[num]>0)
						return false;
					else
						cols[num]++;
				}
			}
		}
		for(int row=0; row<9; row+=3){
			for(int col=0; col<9; col+=3){
				int[] nums = new int[10];
				for (int i = row; i < row + 3; i++) {
					for (int j = col; j < col + 3; j++) {
						if (board[i][j] != '.') {
							int num = board[i][j] - '0';
							if(nums[num]>0)
								return false;
							else
								nums[num]++;
						}
					}
				}
			}
		}
		return true;
    }

	// PASS leetcode#37
	public void solveSudoku(char[][] board) {
		// Start typing your Java solution below
		// DO NOT write main() function
		boolean valid = solve(board, 0, 0);
		// it must be valid...
		System.out.println(board);
	}

	private boolean solve(char[][] board, int row, int col) {

		if (col >= board.length) {
			col = 0;
			row++;
		}
		if (row >= board.length){
			return true;
		}

		if (board[row][col] == '.') {
			int[] nums = collectNums(board, row, col);
			for (int i = 1; i < 10; i++) {
				if (nums[i] > 0)
					continue;
				board[row][col] = (char) (i + '0');
				if(solve(board, row, col + 1))
					return true;
				board[row][col] = '.';
			}
			return false;
		} else {
			return solve(board, row, col + 1);
		}
	}

	private int[] collectNums(char[][] board, int row, int col) {
		int[] nums = new int[10];// initialized to be zeros
		for (int i = 0; i < board.length; i++) {
			if (board[row][i] != '.') {
				nums[board[row][i] - '0']++;
			}
			if (board[i][col] != '.') {
				nums[board[i][col] - '0']++;
			}
		}
		row -= row % 3;
		col -= col % 3;
		for (int i = row; i < row + 3; i++) {
			for (int j = col; j < col + 3; j++) {
				if (board[i][j] != '.') {
					nums[board[i][j] - '0']++;
				}
			}
		}
		return nums;
	}

	public static void main(String args[]) {
		char[][] board = { 
				{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
				{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
				{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
				{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
				{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
				{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
				{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
				{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
				{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
		Solution sol = new Solution();
//		sol.solveSudoku(board);
		boolean valid = sol.isValidSudoku(board);
		System.out.println(valid);
	}
}
