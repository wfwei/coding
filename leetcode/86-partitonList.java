public ListNode partition(ListNode head, int x) {
    // Start typing your Java solution below
    // DO NOT write main() function
    ListNode cur = new ListNode(0);
    cur.next = head;
    head = cur;
    
    ListNode small=cur, big=cur;
    while(small.next!=null && small.next.val<x)
        small = small.next;
    big = small.next;
    
    if(big!=null){
        while((cur=big.next)!=null){
            if(cur.val>=x){
                big = cur;
            }else{
                big.next = cur.next;
                cur.next = small.next;
                small.next = cur;
                small = small.next;
            }
        }
    }
    return head.next;
}
