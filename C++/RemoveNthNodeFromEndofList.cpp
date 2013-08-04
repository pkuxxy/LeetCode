#include<iostream>
#include<stdlib.h>
#include<vector>
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)
			return NULL;
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* tail = head;
		while(n--)
		{
			tail = tail->next;
		}
		while(tail)
		{
			pre = cur;
			cur = cur->next;
			tail = tail->next;
		}
		if(!pre)
		{
			head = head->next;
			free(cur);
			return head;
		}
		pre->next = cur->next;
		free(cur);
		return head;
	}
};