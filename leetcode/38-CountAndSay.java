public class Test {

    public String countAndSay(int n) {
	if (n <= 1)
	    return String.valueOf(n);
	StringBuilder sb = new StringBuilder("1");
	while (n > 1) {
	    String str = sb.toString();
	    sb.setLength(0);
	    for (int i = 0; i < str.length();) {
		int j = i + 1;
		char cur = str.charAt(i);
		while (j < str.length() && str.charAt(j) == cur) {
		    j++;
		}
		sb.append(j-i).append(cur);
		i = j;
	    }
	    n--;
	}
	return sb.toString();
    }

    public static void main(String[] args) {
	System.out.println(new Test().countAndSay(1));
	System.out.println(new Test().countAndSay(2));
    }
}