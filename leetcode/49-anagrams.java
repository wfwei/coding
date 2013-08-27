import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class Solution {

	public ArrayList<String> anagrams(String[] strs) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashMap<String, ArrayList<String>> strMap = new HashMap<String, ArrayList<String>>();
        ArrayList<String> results = new ArrayList<String>();
        HashSet<String> resSet = new HashSet<String>();
		for(String str:strs){
			String sortedStr = sortStr(str);
			ArrayList<String> list = strMap.get(sortedStr);
			if(list == null){
				list = new ArrayList<String>();
				strMap.put(sortedStr, list);
			}
			list.add(str);
			if(list.size()>1){
				resSet.add(sortedStr);
			}
		}
		for(String sortedStr:resSet){
			results.addAll(strMap.get(sortedStr));
		}
		return results;
    }
	
	private String sortStr(String str){
		char[] chars = str.toCharArray();
		Arrays.sort(chars);
		return new String(chars);
	}

	public static void main(String[] args) {
		Solution t = new Solution();
		System.out.println(t.anagrams(new String[] {"tea","and","ate","eat","den" }));
	}
}

