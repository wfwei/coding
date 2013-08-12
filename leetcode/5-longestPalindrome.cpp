//============================================================================
// Name        : Coding.cpp
// Author      : Plex
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		string rs(s.rbegin(), s.rend());
		return longestCommonSubstring(s, rs);
	}

//	string longestCommonSubstring(string s1, string s2) {
//
//		int len1 = s1.length(), len2 = s2.length();
//		int dp[len1+1][2];
//
//		int maxLen = 0, maxIdx = 0;
//		int i, j, k;
//		memset(dp, 0, sizeof(dp));
//		for(i=0, k=1; i<len2; i++){
//			memset(dp[k], 0, sizeof(dp[k]));//清空当前状态数组
//			for(j=len1-1; j>=0; j--){
//				if(s1[j]==s2[i]){
//					dp[k][j+1] = dp[1-k][j]+1;
//					if(dp[k][j+1]>maxLen)
//						maxLen=dp[k][j+1], maxIdx=j;
//				}
//			}
//			k=(k==1)?0:1;
//		}
//
//		string str;
//		if (maxLen > 0) {
//			for (i = maxIdx - maxLen + 1; i <= maxIdx; i++)
//				str += s1[i];
//		}
//		return str;
//	}

	string longestCommonSubstring(string s1, string s2) {

			int len1 = s1.length(), len2 = s2.length();
			int dp[len1 + 1][len2 + 1];

			memset(dp, 0, sizeof(dp));

			int maxLen = 0, maxIdx = 0;
			int i, j;
			for (i = 1; i <= len1; i++) {
				for (j = 1; j <= len2; j++) {
					if (s1[i - 1] == s2[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
						// 第二个条件是公共字串的位置对称，如果没有要求，可以去掉
						if (dp[i][j] > maxLen && i+j==dp[i][j]+len1) {
							maxLen = dp[i][j];
							maxIdx = i - 1;
						}
					}
				}
			}

			string str;
			if (maxLen > 0) {
				for (i = maxIdx - maxLen + 1; i <= maxIdx; i++)
					str += s1[i];
			}
			return str;
		}
};

int main() {
	Solution sol;
	string s = "abccbd";
	string res = sol.longestPalindrome(s);
//	string s1 = "abcd", s2 = "acdb";
//	string res = sol.longestCommonSubstring(s1, s2);
	cout << res;
	return 0;
}

