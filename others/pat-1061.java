import java.util.Scanner;

public class CopyOfMain {

  static String[] map = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	private static boolean isChar(char a) {
		return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
	}

	private static boolean isDigit(char a) {
		return a >= '0' && a <= '9';
	}

	private static char[] CommonChars(String a, String b) {
		char[] res = new char[2];
		int c = 0, c1 = 0;
		for (int i = 0; i < a.length() && i < b.length(); i++) {

			if (a.charAt(i) == b.charAt(i) && isChar(a.charAt(i))) {
				c1++;
				if (c1 == 2)
					res[1] = a.charAt(i);
				if (c == 0 && a.charAt(i) >= 'A' && a.charAt(i) <= 'Z') {
					res[0] = a.charAt(i);
					c++;
				}
				if (c > 0 && c1 > 1)
					break;
			}
		}

		return res;
	}

	private static int firstCommonCharPos(String a, String b) {
		for (int i = 0; i < a.length() && i < b.length(); i++)
			if (a.charAt(i) == b.charAt(i) && isChar(a.charAt(i)))
				return i;
		return 0;
	}

	public static String ParseDate(String a, String b, String c, String d) {
		StringBuffer res = new StringBuffer();
		char[] chars = CommonChars(a, b);

		int weekDay = chars[0] - 'A';
		res.append(map[weekDay % 7]).append(" ");

		char lchar = chars[1];
		if (isDigit(lchar)) {
			res.append(lchar - '0').append(":");
		} else {
			res.append(lchar - 'A' + 10).append(":");
		}

		int cpos = firstCommonCharPos(c, d);
		int hp = cpos / 10, lp = cpos % 10;
		res.append((char) (hp + '0')).append((char) (lp + '0'));
		return res.toString();
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		String b = sc.nextLine();
		String c = sc.nextLine();
		String d = sc.nextLine();

		System.out.println(ParseDate(a, b, c, d));
	}

}

