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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		ListNode* head = NULL;
		ListNode* cur = head;
		if(l1->val < l2->val)
		{
			head = cur = l1;
			l1 = l1->next;
		}
		else
		{
			head = cur = l2;
			l2 = l2->next;
		}
		while(l1 && l2)
		{
			if(l1->val <= l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		while(l1)
		{
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		while(l2)
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
		return head;
	}
};