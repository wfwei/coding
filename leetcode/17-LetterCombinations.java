import java.util.ArrayList;

public class Test {

    public ArrayList<String> letterCombinations(String digits) {
    ArrayList<String> res = new ArrayList<String>();
    letterCombinations(digits, 0, digits.length() - 1, res,
        new StringBuilder());
    return res;
    }

    static String table[] = { " ", "", "abc", "def", "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz" };

    public void letterCombinations(String digits, int s, int e,
        ArrayList<String> res, StringBuilder sb) {
    if (s <= e) {
        String chars = table[digits.charAt(s) - '0'];
        if (chars.length() == 0) {
        letterCombinations(digits, s + 1, e, res, sb);
        }
        for (int j = 0; j < chars.length(); j++) {
        sb.append(chars.charAt(j));
        letterCombinations(digits, s + 1, e, res, sb);
        sb.setLength(sb.length() - 1);
        }
    } else {
        res.add(sb.toString());
    }
    }

    public static void main(String[] args) {
    new Test().letterCombinations("123");
    }
}
