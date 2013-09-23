public class MinPathSum {

	public int minPathSum(int[][] grid) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(grid==null || grid.length==0)
            return 0;
        int rowcnt = grid.length, colcnt = grid[0].length;
        int[] dp = new int[colcnt];
        if(colcnt>1)
            Arrays.fill(dp, 1, colcnt, Integer.MAX_VALUE);
        for(int i=0; i<rowcnt; i++){
            dp[0] += grid[i][0];
            for(int j=1; j<colcnt; j++){
                dp[j] = Math.min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[colcnt-1];
    }
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MinPathSum sol = new MinPathSum();
		int[][] grid = {{1,3,1},{1,5,1},{4,2,1}};
		int res = sol.minPathSum(grid);
		System.out.println(res);
	}

}
