#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	// kmp search needle in haystack, only use pointers
	char *strStr(char *haystack, char *needle) {
		if(!haystack || !needle)
			return NULL;
		int i, j, next[100000]={0};
		for(i=1; needle[i]; i++){
			if(needle[i] == needle[next[i-1]])
				next[i] = next[i-1]+1;
			else
				next[i] = 0;
		}

		for(i=0, j=0; haystack[j]&&needle[i]; ){
			if(needle[i] == haystack[j]){
				i++; j++;
			}else{
				if(i==0){
					j++;
				}else{
					i = next[i-1];
				}
			}
		}
		if(!needle[i])
			return haystack + (j-i);
		else
			return NULL;
	}
	// kmp search needle in haystack, use strlen
	char *strStr2(char *haystack, char *needle) {
			if(!haystack || !needle)
				return NULL;
			int i, j, len1 = strlen(haystack), len2=strlen(needle);
			int *next = (int *)malloc(len2 * sizeof(int));
			for(i=1; i<len2; i++){
				if(needle[i] == needle[next[i-1]])
					next[i] = next[i-1]+1;
				else
					next[i] = 0;
			}

			for(i=0, j=0; i<len2&&j<len1; ){
				if(needle[i] == haystack[j]){
					i++; j++;
				}else{
					if(i==0){
						j++;
					}else{
						i = next[i-1];
					}
				}
			}
			if(i>=len2 && j>=len2)
				return haystack + (j-len2);
			else
				return NULL;
		}
};

int main() {
	Solution sol;
//	cout << sol.strStr("abadabab", "abab") << endl;
	cout << sol.strStr("aaa", "aaaa") << endl;
	return 0;
}
