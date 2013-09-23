/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isBalanced(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	boolean[] valid = new boolean[]{true};
		depth(root, valid);
		return valid[0];
    }
	
	private int depth(TreeNode root, boolean[] valid){
		if(root==null || !valid[0])
			return 0;

		int ld = depth(root.left, valid);
		int rd = depth(root.right, valid);
		
		if(Math.abs(ld-rd)>1){
			valid[0] = false;
			return 0;
		}
		else
			return Math.max(ld, rd) + 1;
	}
}
