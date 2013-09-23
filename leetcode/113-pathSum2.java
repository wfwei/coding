import java.util.ArrayList;

public class Solution {
    
    public void tranverse(TreeNode root, int sum, 
        ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res){
        
        if(root!=null){
            
            sum -= root.val;
            cur.add(root.val);
            
            if(root.left==null && root.right==null && sum==0){
                // find one path
                res.add(new ArrayList<Integer>(cur)); // trap, 一定要构建新对象
            } else {
                tranverse(root.left, sum, cur, res);
                tranverse(root.right, sum, cur, res);
            }

            cur.remove(cur.size()-1);
        }
        
        
    }
    
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        tranverse(root, sum, new ArrayList<Integer>(), res);
        return res;
    }
    
    public static void main(String[] args) {
    	TreeNode root = new TreeNode(1);
    	Solution sol = new Solution();
    	ArrayList<ArrayList<Integer>> res = sol.pathSum(root, 1);
    	System.out.println(res);
	}
    
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
}
