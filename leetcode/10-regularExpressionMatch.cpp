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
	// if appears *, the preceding charactor matches zero or more characters
	bool isMatch(const char *s, const char *p) {

		int slen = strlen(s), plen = strlen(p);
		int i, j;
		for (i = 0, j = 0; i < plen && j < slen;) {
			cout << s + j << '\t' << p + i << endl;

			if (i + 1 < plen && p[i + 1] == '*') {
				bool match = isMatch(s + j, p + i + 2);
				while (!match && j < slen && (s[j] == p[i] || p[i] == '.')) {
					match = isMatch(s + j + 1, p + i + 2);
					if (!match)
						j++;
				}
				return match;
			} else {
				if(p[i]=='.' || p[i]==s[j])
					i++, j++;
				else
					return false;
			}
		}

		if (j < slen)
			return false;

		while (i < plen) {
			if(i+1<plen && p[i+1]=='*')
				i+=2;
			else
				return false;
		}
		return true;
	}

	// * match zero or more preceding charactor, but the preceding charactor must match a character
	bool isMatch2(const char *s, const char *p) {

		//    	int slen=sizeof(s)/sizeof(s[0]), plen=sizeof(p)/sizeof(p[0]);
		int slen = strlen(s), plen = strlen(p);
		int i, j;
		for (i = 0, j = 0; i < plen && j < slen;) {
			//        	cout << s+j << '\t' << p+i <<endl;
			if (p[i] == '.') {
				i++;
				j++;
			} else if (p[i] == '*') {
				if (i > 0) {
					while (j - 1 < slen
							&& (s[j - 1] == p[i - 1] || p[i - 1] == '.')) {
						bool res = isMatch(s + j, p + i + 1);
						if (res)
							return true;
						else
							j++;
					}
					return false;
				} else {
					i++;
				}

			} else {
				if (p[i] == s[j]) {
					j++;
					i++;
				} else {
					return false;
				}
			}
		}

		if (j < slen)
			return false;

		while (i < plen) {
			if (p[i] != '*')
				return false;
			i++;
		}
		return true;
	}
};

int main() {
	Solution sol;
	cout << sol.isMatch("aab", "c*a*b") << "==1" << endl;
	cout << sol.isMatch("ba", ".*a*a") << "==1" << endl;
	cout << sol.isMatch("aaab", "a*aab") << "==1" << endl;
	cout << sol.isMatch("aa", "aa") << "==1" << endl;
	cout << sol.isMatch("aa", ".*c") << "==0" << endl;
	return 0;
}

