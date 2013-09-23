import java.util.ArrayList;

public class PalindromePartition {
	
	// 判断子串str[sidx:eidx]是不是回文串
	public boolean isPalindrome(String str, int sidx, int eidx){
		
		while(sidx<eidx && str.charAt(sidx)==str.charAt(eidx)){
			sidx++;eidx--;
		}
		
		return sidx>=eidx;
	}
	
	// 找到所有从sidx开始的回文子串，保存其尾坐标eidx到列表中返回
	public ArrayList<Integer> findPalindromeEnds(String str, int sidx){
		
		ArrayList<Integer> res = new ArrayList<Integer>();
		
		for(int eidx = sidx; eidx<str.length(); eidx++){
			if(isPalindrome(str, sidx, eidx))
				res.add(eidx);
		}
		
		return res;
	}
	
	// 分裂从sidx开始的子串
	public void partition(String str, Integer sidx, ArrayList<String> cur, ArrayList<ArrayList<String>> res){
		
		if(sidx>=str.length()){
			// 结束，保存结果
			res.add(new ArrayList<String>(cur));
		}else{
			for(Integer eidx : findPalindromeEnds(str, sidx))	{
				cur.add(str.substring(sidx, eidx+1));
				partition(str, eidx+1, cur, res); //递归分裂剩下的子串
				cur.remove(cur.size()-1); //回朔
			}
		}
	}

	public ArrayList<ArrayList<String>> partition(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
		ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
        partition(s, 0, new ArrayList<String>(), res);
		return res;
    }

	public static void main(String[] args) {
		PalindromePartition sol = new PalindromePartition();
		String string = "cbbbcc";
		ArrayList<ArrayList<String>> res = sol.partition(string);
		for(ArrayList<String> part:res){
			System.out.println("");
			for(String str:part){
				System.out.print(str+" ");
			}
		}
	}
}
