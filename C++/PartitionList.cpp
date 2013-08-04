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
	//int getLen(ListNode* head)
	//{
	//	int len = 0;
	//	while(head)
	//	{
	//		len++;
	//		head = head->next;
	//	}
	//	return len;
	//}
	ListNode *partition(ListNode *head, int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)
			return head;
		ListNode* end = head;
		while(end->next)
		{
			end = end->next;
		}
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* tail = end;
		while(cur != end)
		{
			ListNode* next = cur->next;
			if(cur->val >= x)
			{
				if(pre)
				{
					pre->next = next;
				}
				tail->next = cur;
				tail = tail->next;
				tail->next = NULL;
			}
			else
			{
				if(!pre)
				{
					head = cur;
				}
				pre = cur;
			}
			cur = next;
		}
		if(cur->val >= x)
		{
			ListNode* next = cur->next;
			if(pre)
			{
				if(next)
					pre->next = cur->next;
			}
			tail->next = cur;
			cur->next = NULL;
		}
		else
		{
			if(!pre)
			{
				head = cur;
			}
		}
		return head;
	}
};