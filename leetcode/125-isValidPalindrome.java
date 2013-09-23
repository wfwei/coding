public class ValidPalindrome {

	private static final int INVALID = -1;

	public int getValidCode(char c) {

		if (c >= 'a' && c <= 'z')
			return c - 'a';

		if (c >= 'A' && c <= 'Z')
			return c - 'A';

		if (c >= '0' && c <= '9')
			return c + 1000;

		return INVALID;
	}

	// 这个是最开始的思路，一步一步的判断流程，其实好多判断可以优化掉
	public boolean isPalindrome(String str) {
		// Start typing your Java solution below
		// DO NOT write main() function
		int s = 0, e = str.length() - 1;

		while (s < e) {

			// find first valid char
			int scode = getValidCode(str.charAt(s));
			while (scode == INVALID && s < e) {
				s++;
				scode = getValidCode(str.charAt(s));
			}

			if (scode >= 0) {
				// find the 'palindrome' one char
				int ecode = getValidCode(str.charAt(e));
				while (ecode == INVALID && s < e) {
					e--;
					ecode = getValidCode(str.charAt(e));
				}
				if (ecode != scode)
					return false;
				else {
					s++;
					e--;
				}
			}
		}

		return true;
	}

	// 这里是对上面思路的代码优化结果，一开始写成这样就大牛了
	public boolean isPalindrome1(String str) {

		for (int s = 0, e = str.length() - 1; s < e; s++, e--) {
			int scode = INVALID, ecode = INVALID;
			while (s < e && (scode = getValidCode(str.charAt(s))) == INVALID)
				s++;
			while (s < e && (ecode = getValidCode(str.charAt(e))) == INVALID)
				e--;
			if (scode != ecode)
				return false;
		}
		return true;

	}

	// 参考的别人代码
	public boolean isPalindrome2(String str) {

		for (int s = 0, e = str.length() - 1; s < e; s++, e--) {
			while (s < e && !Character.isLetterOrDigit(str.charAt(s)))
				s++;
			while (s < e && !Character.isLetterOrDigit(str.charAt(e)))
				e--;
			if (Character.toLowerCase(str.charAt(s)) != Character
					.toLowerCase(str.charAt(e)))
				return false;
		}
		return true;

	}

	public static void main(String[] args) {
		ValidPalindrome sol = new ValidPalindrome();
		System.out.format("%s == false\n", sol.isPalindrome1("1a2"));
		System.out.format("%s == true\n",
				sol.isPalindrome1("A man, a plan, a canal: Panama"));
	}

}
