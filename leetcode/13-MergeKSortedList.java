import java.util.ArrayList;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
	val = x;
	next = null;
    }

    public String toString() {
	return val + "";
    }
}

public class Test {

    public ListNode mergeKLists(ArrayList<ListNode> lists) {

	if (lists == null || lists.size() == 0)
	    return null;

	ListNode result = new ListNode(0);
	ListNode newl = result;

	ListNode[] heap = new ListNode[lists.size()];
	int len = 0;
	for (ListNode node : lists) {
	    if (node != null) {
		heap[len] = node;
		len++;
	    }
	}

	for (int i = len / 2 - 1; i >= 0; i--) {
	    adjustHeap(heap, i, len - 1);
	}

	while (heap[0] != null && heap[0].val < Integer.MAX_VALUE) {
	    newl.next = heap[0];
	    newl = newl.next;
	    heap[0] = heap[0].next;
	    if (heap[0] == null)
		heap[0] = new ListNode(Integer.MAX_VALUE);
	    adjustHeap(heap, 0, len - 1);
	}

	return result.next;
    }

    public void adjustHeap(ListNode[] heap, int s, int e) {
	ListNode cur = heap[s];
	int i;
	for (i = s; i <= e;) {
	    int child = i * 2 + 1;

	    if (child > e)
		break;
	    if (child < e && heap[child].val > heap[child + 1].val)
		child++;

	    if (heap[child].val < cur.val) {
		heap[i] = heap[child];
		i = child;
	    } else
		break;
	}
	heap[i] = cur;
    }

    public static void main(String[] args) {
	ArrayList<ListNode> lists = new ArrayList<ListNode>();
	lists.add(null);
	ListNode head;
	head = new ListNode(1);
	head.next = new ListNode(5);
	head.next.next = new ListNode(6);
	lists.add(head);
	head = new ListNode(2);
	head.next = new ListNode(3);
	head.next.next = new ListNode(7);
	lists.add(head);
	head = new ListNode(1);
	lists.add(head);

	ListNode res = new Test().mergeKLists(lists);
	System.out.println("==========================");
	while (res != null) {
	    System.out.println(res.val);
	    res = res.next;
	}
    }
}
