#include<stdlib.h>
#include<vector>
#include<unordered_set>
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
	ListNode *deleteDuplicates(ListNode *head) {
		if(!head)
			return head;
		ListNode* newhead = head;
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while(cur && next)
		{
			if(cur->val == next->val)
			{
				while(cur && next && cur->val == next->val)
				{
					delete cur;
					cur = next;
					next = cur->next;
				}
				delete cur;
				if(pre)
					pre->next = next;
				else
					newhead = next;
				cur = next;
				if(cur)
					next = cur->next;
			}
			else
			{
				pre = cur;
				cur = next;
				next = cur->next;
			}
		}
		return newhead;
	}
};