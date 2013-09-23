public ListNode reverseBetween(ListNode head, int m, int n) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(m<0 || n<=m)
        return head;
    ListNode nhead = new ListNode(0);
    nhead.next = head;
    ListNode st=nhead, cur=nhead, target;
    for(int i=1; i<m && st!=null; i++)
        st = st.next;
    if(st==null || (cur = st.next)==null)
        return head;
    for(int i=m; i<n && (target = cur.next)!=null; i++){
        cur.next = target.next;
        target.next = st.next;
        st.next = target;
    }
    return nhead.next;
}
