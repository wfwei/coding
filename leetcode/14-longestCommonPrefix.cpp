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
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int i, j, len = strs.size();
		string res = strs.empty() ? "" : strs[0];

		for (i = 1; i < len && res.length() > 0; i++) {

			for (j = 0; j < res.length() && j < strs[i].length(); j++) {
				if (res[j] != strs[i][j])
					break;
			}
			res.resize(j);

		}
		return res;
	}
};

int main() {
	Solution sol;
	vector<string> s;
	s.push_back("aa");
	s.push_back("aad");
	cout << sol.longestCommonPrefix(s) << endl;
	return 0;
}
