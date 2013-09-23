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
    
    // 一次bingo，太爽了    
    public boolean hasPathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null)
            return false;
        else
            sum -= root.val;
        
        if(root.left==null && root.right==null && sum==0)
            return true;
        
        if(hasPathSum(root.left, sum) || hasPathSum(root.right, sum))
            return true;
        
        return false;
    }
}
