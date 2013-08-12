import java.util.Comparator;
import java.util.HashMap;
import java.util.TreeMap;

public class 13-Roman {

    static class IntToRoman {
    public int romanToInt(String s) {
        int res = 0;

        return res;
    }

    static TreeMap<Integer, String> mapper = new TreeMap<Integer, String>(
        new Comparator<Integer>() {
            @Override
            public int compare(Integer i1, Integer i2) {
            return i2.compareTo(i1);
            }
        });
    static {
        mapper.put(1, "I");
        mapper.put(4, "IV");
        mapper.put(5, "V");
        mapper.put(9, "IX");
        mapper.put(10, "X");
        mapper.put(40, "XL");
        mapper.put(50, "L");
        mapper.put(90, "XC");
        mapper.put(100, "C");
        mapper.put(400, "CD");
        mapper.put(500, "D");
        mapper.put(900, "CM");
        mapper.put(1000, "M");
    }

    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
        for (Integer in : mapper.keySet()) {
            if (num >= in) {
            sb.append(mapper.get(in));
            num -= in;
            break;
            }
        }
        }
        return sb.toString();
    }
    }

    static class RomanToInt {
    public int romanToInt(String s) {
        int res = 0, cur = 0, maxVal = Integer.MAX_VALUE;
        while (cur < s.length()) {
        boolean valid = false;
        for (String roman : mapper.keySet()) {
            if (s.startsWith(roman.substring(2), cur)) {
            if (mapper.get(roman) <= maxVal) {
                res += mapper.get(roman);
                cur += roman.length() - 2;
                String sub = roman.substring(2, 3);
                maxVal = basicNums.get(sub);
                valid = true;
                break;
            }
            }
        }
        if (!valid)
            return 0;// éæ³è¾å¥
        }
        return res;
    }

    static TreeMap<String, Integer> mapper = new TreeMap<String, Integer>();
    static {
        mapper.put("12I", 1);
        mapper.put("11IV", 4);
        mapper.put("10V", 5);
        mapper.put("09IX", 9);
        mapper.put("08X", 10);
        mapper.put("07XL", 40);
        mapper.put("06L", 50);
        mapper.put("05XC", 90);
        mapper.put("04C", 100);
        mapper.put("03CD", 400);
        mapper.put("02D", 500);
        mapper.put("01CM", 900);
        mapper.put("00M", 1000);
    }
    static HashMap<String, Integer> basicNums = new HashMap<String, Integer>();
    static{
        basicNums.put("I", 1);
        basicNums.put("V", 5);
        basicNums.put("X", 10);
        basicNums.put("L", 50);
        basicNums.put("C", 100);
        basicNums.put("D", 500);
        basicNums.put("M", 1000);
    }
    }

    public static void main(String[] args) {
    IntToRoman int2Roman = new IntToRoman();
    RomanToInt roman2int = new RomanToInt();

    int re = roman2int.romanToInt("XCL");
    System.out.println(re);
    for (int i = 1; i < 4000; i++) {
        if (i != roman2int.romanToInt(int2Roman.intToRoman(i))) {
        System.out.println("\nerror for integer: " + i);
        }
    }
    System.out.println("over~~");
    }
}
