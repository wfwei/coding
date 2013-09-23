public class Flatten {
static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }


    // TLE 关键是，为什么会超时呢
    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        flatten(root, null);        
    }
    private void flatten(TreeNode root, TreeNode tail){
        if(root==null)
            return ;
            
        if(root.right==null)
            root.right = tail;
        else
            flatten(root.right, tail);
        
        if(root.left!=null){
            flatten(root.left, root.right);
            root.right = root.left;
            root.left = null;
        }
        flatten(root.right, null);
    }

    // 理清楚思路后，其实就是二叉树的先序遍历
    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
		Stack<TreeNode> st = new Stack<TreeNode>();
		
		while(root!=null){
			if(root.right != null)
				st.push(root.right);
			if(root.left != null)
				st.push(root.left);
			if(!st.isEmpty())
				root.right = st.pop();
			else
				root.right = null; // Over
			root.left = null;
			root = root.right;
		}
    }

    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        deal(root);
    }
    // 带返回值的递归，思路比较清晰
    private TreeNode deal(TreeNode root){
        
        if(root==null)
            return null;
        
        TreeNode lend=deal(root.left), rend=deal(root.right);
        
        if(lend!=null){
            lend.right = root.right;
            lend.left = null;
            root.right = root.left;
            root.left = null;
            if(rend==null)
                rend = lend;
        }
        if(rend==null)
            rend = root;
        return rend;
    }
}

