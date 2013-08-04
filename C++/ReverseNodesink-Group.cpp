#include<iostream>
#include<vector>
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head )
			return head;
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* end = head;
		while(true)
		{
			int tmp = k;
			tmp--;
			while(tmp-- && end)
				end = end->next;
			if(!end)
				break;
			while(cur != end)
			{
				ListNode* next1 = cur->next;
				ListNode* next2 = end->next;
				end->next = cur;
				cur->next = next2;
				cur = next1;
			}
			if(pre)
			{
				pre->next = end;
			}
			else
			{
				head = end;
			}
			tmp = k;
			tmp--;
			pre = end;
			while(tmp--)
			{
				pre = pre->next;
			}
			cur = end = pre->next;
		}
		return head;
	}
};