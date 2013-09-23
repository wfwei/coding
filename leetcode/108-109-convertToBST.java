static class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
static class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; next = null; }
}
// internal err??
public TreeNode sortedListToBST(ListNode head) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(head==null)
        return null;
    ListNode fast=head, slow=head;
    while(fast!=null){
        fast = fast.next;
        if(fast==null)
            break;
        fast = fast.next;
        slow = slow.next;
    }
    
    TreeNode root = new TreeNode(slow.val);
    fast = slow.next;
    slow.next = null;
    root.left = sortedListToBST(head);
    root.right  = sortedListToBST(fast);
    return root;
}

// Internel Error...
public TreeNode sortedArrayToBST(int[] num) {
    // Start typing your Java solution below
    // DO NOT write main() function
    return sortedArrayToBST(num, 0, num.length-1);
}

private TreeNode sortedArrayToBST(int[] num, int s, int e){
    if(e>s)
        return null;
    int mid = s + (e-s)/2;
    TreeNode root = new TreeNode(num[mid]);
    root.left = sortedArrayToBST(num, s, mid-1);
    root.right = sortedArrayToBST(num, mid+1, e);
    return root;
}
