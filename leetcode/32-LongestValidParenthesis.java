public class Solution {

	public int longestValidParentheses(String s) {
		// Start typing your Java solution below
		// DO NOT write main() function
		StringBuilder sb = new StringBuilder();
		int max = 0;
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case '(':
				sb.append('(');
				break;
			case ')':
				int len = sb.length();
				if (len > 0) {
					if (sb.charAt(len - 1) == '(')
						sb.setCharAt(sb.length() - 1, '1');
					else {
						if (len > 1)
							sb.setCharAt(sb.length() - 2, '1');
						else{
							sb.setLength(0);
							break;
						}
					}
					int count = 0, e;
					for (e = len - 1; e >= 0; e--) {
						if (sb.charAt(e) != '(') {
							count += sb.charAt(e) - '0';
						} else
							break;
					}
					if (count > 0) {
						sb.setCharAt(e + 1, (char) (count + '0'));
						sb.setLength(e + 2);
						if (count > max)
							max = count;
					}

				}
			}
		}
		return max + max;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.print(sol.longestValidParentheses("())"));
	}
}
