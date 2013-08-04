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
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)
			return head;
		ListNode* start = head;
		ListNode* pre = NULL;
		ListNode* end = head;
		m--;
		n--;
		while(m--)
		{
			pre = start;
			start = start->next;
		}
		while(n--)
			end = end->next;
		while(start != end)
		{
			ListNode* next1 = start->next;
			ListNode* next2 = end->next;
			if(pre)
				pre->next = next1;
			end->next = start;
			start->next = next2;
			start = next1;
		}
		if(!pre)
			head = end;
		return head;


	}
};