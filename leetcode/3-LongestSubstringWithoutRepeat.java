import java.util.Iterator;
import java.util.LinkedHashSet;


public class Solution {
	
	public int lengthOfLongestSubstring(String str) {
		if(str==null || str.length()==0)
			return 0;
		if(str.length()==1)
			return 1;
		LinkedHashSet<Character> set = new LinkedHashSet<Character>();
        int len=str.length(), idx, maxL=1;
        set.add(str.charAt(0));
        
        for(idx=1;idx<len;idx++){
        	char c = str.charAt(idx);
        	if(set.contains(c)){
        		Iterator<Character> iter = set.iterator();
        		while(iter.hasNext()){
        			char cc = iter.next();
        			iter.remove();
        			if(cc == c)
        				break;
        		}
        	}
        	set.add(c);
        	if(set.size()>maxL)
        		maxL = set.size();
        }
        
        
        return maxL;
        
    }

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Solution sol = new Solution();
		String str = "htskcpwxnvsplgkbgzuoxbwpmbfxeumnnfzruvphthxeojiwiclgfjxtndrtzdgmiffc";
		System.out.print(sol.lengthOfLongestSubstring(str));
	}

}
