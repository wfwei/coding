public class Solution {
  // big num multiply
	public String multiply(String num1, String num2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        StringBuilder res = new StringBuilder();
        int imax=num1.length()-1, jmax=num2.length()-1, i, j;
        for(i=imax; i>=0; i--){
            int carry=0;
            for(j=jmax; j>=0; j--){
                int s = (num1.charAt(i)-'0')*(num2.charAt(j)-'0')+carry;
                int pos = jmax-j+imax-i;
                if(pos>=res.length())
                	res.append((char)('0' + s%10));
                else
                	res.setCharAt(pos, (char)(res.charAt(pos)+s%10));
                carry = s/10;
            }
            if(carry>0){
            	res.append((char)(carry+'0'));
            }
            carry = 0;
            for(int k=0; k<res.length(); k++){
            	int val = res.charAt(k) - '0' + carry;
            	carry = val/10;
            	res.setCharAt(k, (char)(val%10 + '0'));
            }
            if(carry>0){
            	res.append((char)(carry+'0'));
            }
        }
        for(int k=res.length()-1; k>0&&res.charAt(k)=='0'; k--)
        	res.setLength(k);
        return res.reverse().toString();
    }

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.println(sol.multiply("0", "276"));
	}
}
