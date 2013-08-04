#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		while(p1 && p2)
		{
			if(!p1->next && p2->next)
				p1->next = new ListNode(0);
			p1->val += p2->val;
			if(p1->val >= 10)
			{
				p1->val %= 10;
				if(!p1->next)
					p1->next = new ListNode(0);
				p1->next->val += 1;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		while(p1)
		{
			if(p1->val >= 10)
			{
				p1->val %= 10;
				if(!p1->next)
					p1->next = new ListNode(0);
				p1->next->val += 1;
			}
			p1 = p1->next;
		}
		return l1;
	}
};