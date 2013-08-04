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
struct ComNode
{
	bool operator()(ListNode* p1, ListNode* p2)
	{
		return p1->val > p2->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode* head = NULL;
		ListNode* pre = NULL;
		priority_queue<ListNode*, vector<ListNode*>, ComNode> heap;
		for(int i = 0; i < lists.size(); i++)
		{
			if(!lists[i])
				continue;
			heap.push(lists[i]);
		}
		while(!heap.empty())
		{
			ListNode* cur = heap.top();
			heap.pop();
			if(!head)
			{
				head = cur;
				pre = head;
				if(cur->next)
					heap.push(cur->next);
			}
			else
			{
				pre->next = cur;
				if(cur->next)
					heap.push(cur->next);
				pre = cur;
			}
		}
		return head;
	}
};
int main()
{
	priority_queue<ListNode*, vector<ListNode*>, ComNode> q;
	vector<ListNode*> lists;
	lists.push_back(new ListNode(0));
	lists.push_back(new ListNode(1));
	Solution sol;
	sol.mergeKLists(lists);
	getchar();
}