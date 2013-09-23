public class UniquePath {

	public int uniquePathsWithObstacles(int[][] grid) {

		int i, j, m = grid.length, n = grid[0].length;
		int[] dp = new int[n];
		dp[0] = 1;
		for (i = 0; i < m; i++) {
			for (j = 1; j < n; j++) {
				if (grid[i][j] == 1)
					dp[j] = 0;
				else
					dp[j] += grid[i][j - 1] == 1 ? 0 : dp[j - 1];
			}
		}

		return dp[n - 1];
	}
	
	public int uniquePathsWithObstacles2(int[][] grid) {

	    int i, j, m = grid.length, n  = grid[0].length;
	    
	    //deal with 1'st line
	    int val=1;
	    for(j=0; j<n; j++){
	        if(grid[0][j]==1)
	            val = 0;
	        grid[0][j] = val;
	    }
	    //deal with the rest
	    val = 1;
	    for(i=1; i<m; i++){
	        if(grid[0][0]==0 || grid[i][0]==1) //!!!grid[0][0] is different from grid[i][0]
	            val = 0;
	        grid[i][0] = val;
	        for(j=1; j<n; j++){
	            if(grid[i][j] == 1)
	                grid[i][j] = 0;
	            else
	                grid[i][j] = grid[i-1][j] + grid[i][j-1];
	        }
	    }
	    
	    return grid[m-1][n-1];
	}

	public int uniquePaths(int m, int n) {
		// make sure: m<n
		if (m > n) {
			m ^= n;
			n ^= m;
			m ^= n;
		}
		long res = 1;
		for (int i = 1; i < m; i++, n++) {
			res = res * n / i;
		}

		return (int) res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		UniquePath up = new UniquePath();
		up.uniquePaths(51, 9);
		up.uniquePathsWithObstacles(new int[][]{{0,0,0},{0,1,0},{0,0,0}});

	}

}
