#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestCommonSequence(string s1, string s2) {

		int len1 = s1.length(), len2 = s2.length();
		int dp[len1 + 1][len2 + 1];

		memset(dp, 0, sizeof(dp));

		int i, j;
		for (i = 1; i <= len1; i++) {
			for (j = 1; j <= len2; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				dp[i][j] = max3(dp[i][j], dp[i - 1][j], dp[i][j - 1]);
			}
		}

		int count = dp[len1][len2], clen = len2 - 1;

		string str;
		for (; clen >= 0; clen--) {
			if (dp[len1][clen] == count)
				continue;
			str += s2[clen];
			count--;
		}
		reverse(str.begin(), str.end());
		return str;
	}

private:
	int max3(int x1, int x2, int x3) {
		if (x1 > x2)
			return x1 > x3 ? x1 : x3;
		else
			return x2 > x3 ? x2 : x3;
	}
};

int main() {
	Solution sol;
	string s1 = "abccdcce", s2="acde";
	string res = sol.longestCommonSequence(s1, s2);
	cout << res;
	return 0;
}
