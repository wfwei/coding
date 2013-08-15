import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
	ArrayList<String> results = new ArrayList<String>();
	gp(n, n, new StringBuilder(), results);
	return results;
    }

    private void gp(int left, int right, StringBuilder sb, ArrayList<String> res) {
	if (left == right && left == 0) {
	    res.add(sb.toString());
	} else {
	    if (left > 0) {
		sb.append("(");
		gp(left - 1, right, sb, res);
		sb.setLength(sb.length() - 1);
	    }
	    if (right > left) {
		sb.append(")");
		gp(left, right - 1, sb, res);
		sb.setLength(sb.length() - 1);
	    }
	}
    }

    public static void main(String[] args) {
	ArrayList<String> results = new Test().generateParenthesis(3);
	for (String res : results) {
	    System.out.println(res);
	}
    }
    
}
