class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)
			return head;
		ListNode* pre = new ListNode(0);
		ListNode* newhead = pre;
		ListNode* cur = head;
		pre->next = cur;
		while(cur && cur->next)
		{
			ListNode* next = cur->next->next;
			pre->next = cur->next;
			cur->next->next = cur;
			cur->next = next;
			pre = cur;
			cur = next;
		}
		head = newhead->next;
		free(newhead);
		return head;
	}
};