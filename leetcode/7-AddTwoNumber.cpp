#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head=new ListNode(0);
        ListNode *cur=head;
        int carry = 0;
        while(l1 || l2){
            int val = carry;
            if(l1){
                val += l1->val;
            l1=l1->next;
            }
            if(l2){
                val += l2->val;
            l2=l2->next;
            }
            carry = val/10;
            val = val%10;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        if(carry!=0)
        	cur->next = new ListNode(carry);
        return head->next;
    }
};

int main() {
	Solution sol;
	ListNode *l1 = new ListNode(5);
//	l1->next = new ListNode(4);
//	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
//	l2->next = new ListNode(6);
//	l2->next->next = new ListNode(4);

	ListNode *res = sol.addTwoNumbers(l1, l2);
	cout << "result:";
	while (res) {
		cout << res->val;
		res = res->next;
	}
	return 0;
}

