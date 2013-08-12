public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode cur = new ListNode(0);
        cur.next = head;
        ListNode right = cur;

        while(n>0 && right!=null){
            right = right.next;
            n--;
        }
        while(right!=null && right.next != null){
            right = right.next;
            cur = cur.next;
        }
        if(cur.next!=head){
            cur.next = cur.next.next;
        }else{
            head = head.next;
        }
        return head;
    }
}
