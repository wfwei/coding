#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = 1;
		unsigned int a = dividend, b = divisor;
		if (dividend < 0) {
			sign = -sign;
			a = -dividend;
		}
		if (divisor < 0) {
			sign = -sign;
			b = -divisor;
		}

		int res = div(a, b);

		if (sign < 0)
			res = -res;
		return res;
	}

	int div(unsigned int dividend, unsigned int divisor) {
		int res = 1;
		unsigned int maxdiv = dividend >> 1;
		unsigned int newdiv = divisor;
		int count = 0;

		while (maxdiv >= newdiv) {
			count++;
			newdiv = newdiv << 1;
		}
		if (count == 0) {
			if (dividend >= divisor)
				res = 1;
			else
				res = 0;
		} else {
			while (count > 0) {
				res += res;
				count--;
			}
			res += div(dividend - newdiv, divisor);
		}
		return res;
	}
};

int main() {
	Solution sol;
	cout << sol.divide(-2147483648, -2147483648) << endl;
	return 0;
}
