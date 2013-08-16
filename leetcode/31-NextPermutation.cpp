#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int i = num.size() - 1;
		while (i > 0 && num[i] <= num[i - 1])
			i--;
		if (i == 0) {
			reverse(num.begin(), num.end());
		} else {

			int j = i;
			while (j < num.size() - 1 && num[j + 1] > num[i - 1])
				j++;

			reverse(num.begin() + i, num.begin() + j);
			if (j + 1 < num.size())
				reverse(num.begin() + j + 1, num.end());

			reverse(num.begin() + i - 1, num.begin() + j);
			reverse(num.begin() + j, num.end());
			reverse(num.begin() + i - 1, num.end());
		}
	}
};

int main() {
	Solution sol;
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(5);
	while (1) {
		sol.nextPermutation(vec);
		cout << vec[0] << vec[1] << vec[2] << vec[3] << vec[4] << endl;
		if (vec[0] == 1)
			break;
	}
	return 0;
}
