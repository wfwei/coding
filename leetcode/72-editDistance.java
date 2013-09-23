
// TLE
public int minDistance(String word1, String word2) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(word1.length()==0)
        return word2.length();
    if(word2.length()==0)
        return word1.length();
    
    if(word1.charAt(0)==word2.charAt(0))
        return minDistance(word1.substring(1), word2.substring(1));
    else{
        return 1 + min(minDistance(word1.substring(1), word2), 
                       minDistance(word1, word2.substring(1)), 
                       minDistance(word1.substring(1), word2.substring(1)));
    }
}
private int min(int a, int b, int c){
    return Math.min(a, Math.min(b, c));
}

// DP
public int minDistance(String word1, String word2) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(word1==null || word2==null)
        return 0;
    int len1 = word1.length(), len2=word2.length();
    int[][] dp = new int[len1+1][len2+1];
    for(int i=0; i<=len1; i++)
        dp[i][0] = i;
    for(int j=0; j<=len2; j++)
        dp[0][j] = j;
    
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(word1.charAt(i-1)==word2.charAt(j-1))
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    
    return dp[len1][len2];
}

// with bug
public int minDistance(String word1, String word2) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(word1==null || word2==null)
        return 0;

    int len1 = word1.length(), len2=word2.length();
    int[][] dp = new int[2][len2+1];

    int cur = 0, last=1;
    for(int j=0; j<=len2; j++)
        dp[last][j] = j;
    for(int i=0; i<len1; i++){
        dp[cur][0] = i+1;
        for(int j=0; j<len2; j++){
            if(word1.charAt(i)==word2.charAt(j))
                dp[cur][j+1] = dp[last][j];
            else{
                dp[cur][j+1] = 1+min(dp[last][j+1], dp[cur][j], dp[last][j]);
            }
        }
        last = cur;
        cur = 1-last;
    }
    
    return dp[last][len2];
}
