public class Main {
	
	public boolean isPalindrome(String str, int sidx, int eidx){
		
		while(sidx<eidx && str.charAt(sidx)==str.charAt(eidx)){
			sidx++;eidx--;
		}
		
		return sidx>=eidx;
	}
	
	// 这样相当于暴搜，TLE
	public int minCut1(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
		int[] dp = new int[s.length()+1];
        dp[0] = 0;
        for(int i=1; i<dp.length; i++){
        	int min = Integer.MAX_VALUE;
        	for(int j=0; j<i; j++){
        		if(isPalindrome(s, j, i-1) && dp[j]<min){
        			min = dp[j];
        		}
        	}
        	dp[i] = min+1;
        }
        
        return dp[s.length()]-1;
    }
	
	// dp
	public int minCut(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
		int[][] dp = new int[s.length()][2];
        dp[0][0]=0; dp[0][1]=0;
        for(int i=1; i<s.length(); i++){
        	int min=Integer.MAX_VALUE, minIdx=i;
        	for(int j = dp[i-1][0]-1; j<=i; j++){
        		if(j>=0 && isPalindrome(s, j, i)){
        			int cut = j>0?dp[j-1][1]+1:0;
        			if(cut<min)
        				min = cut;
        			if(j < minIdx)
        				minIdx = j;
        		}
        	}
        	dp[i][0] = minIdx;
        	dp[i][1] = min;
        }
        
        return dp[s.length()-1][1];
    }
	
	public static void main(String[] args) {
		Main sol = new Main();
//		System.out.println("cbcc Min Cut " + sol.minCut("cbcc"));
//		System.out.println("aa Min Cut " + sol.minCut("aa"));
//		System.out.println("cbbbcc Min Cut " + sol.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"));
//		System.out.println("ac Min Cut " + sol.minCut("ac"));
//		System.out.println("cccc Min Cut " + sol.minCut("cccc"));
		String a="adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";
		for(int len=a.length(); len>0; len--){
			int cut = sol.minCut(a.substring(0, len));
			System.out.println(cut);
			if(cut<=273)
				break;
		}
	}

}
