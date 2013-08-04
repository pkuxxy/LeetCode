#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int getLen(ListNode* head)
	{
		int len = 0;
		while(head)
		{
			len++;
			head = head->next;
		}
		return len;
	}
	ListNode *rotateRight(ListNode *head, int k) {
		if(!head)
			return head;
		int len = getLen(head);
		k %= len;
		if(k == 0)
			return head;
		int tmp = k;
		ListNode* pre = head;
		ListNode* tail = head;
		while(tmp--)
		{
			tail = tail->next;
		}
		while(tail->next)
		{
			pre = pre->next;
			tail = tail->next;
		}
		ListNode* newhead = pre->next;
		pre->next = tail->next;
		tail->next = head;
		return newhead;
	}
};