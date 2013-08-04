#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)
			return NULL;
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode* p = head;
		ListNode *q = head->next;
		while(q)
		{
			if(q->val == p->val)
			{
				p->next = q->next;
				free(q);
				q = p->next;
				continue;
			}
			p = q;
			q = q->next;
		}
		return head;
	}
};