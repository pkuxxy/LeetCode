#include<iostream>
#include<stdlib.h>
#include<stack>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if(!head)
			return head;
		ListNode* newhead = head;
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while(cur && next)
		{
			ListNode* tail = next->next;
			if(pre)
				pre->next = next;
			else
				newhead = next;
			next->next = cur;
			cur->next = tail;
			pre = cur;
			cur = cur->next;
			if(cur)
				next = cur->next;
		}
		return newhead;
	}
};