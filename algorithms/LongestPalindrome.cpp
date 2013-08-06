#include <string>
#include <iostream>

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = s.length();
        int dp[len+1][len+1];
        memset(dp, 0, sizeof(dp));
        
        int i,j;
        for(i=1; i<=len; i++){
            for(j=1; j<=len; j++){
                if(s[i-1]==s[len-j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                dp[i][j] = max3(dp[i][j], dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int count = dp[len][len], clen=len;
        string str;
        while(clen>0){
            clen--;
            if(dp[len][clen]==count)
                continue;
            str.append(&s[clen]);
            count --;
        }
        return str;
    }
    
private:
    int max3(int x1, int x2, int x3){
        if(x1>x2)
            return x1>x3?x1:x3;
        else
            return x2>x3?x2:x3;
        
    }
};
