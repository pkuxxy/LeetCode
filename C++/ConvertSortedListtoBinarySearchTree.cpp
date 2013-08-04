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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* genTree(vector<int>& list, int s, int e)
	{
		if(s > e)
			return NULL;
		int mid = (s+e)/2;
		TreeNode* root = new TreeNode(list[mid]);
		root->left = genTree(list, s, mid-1);
		root->right = genTree(list, mid+1, e);
		return root;
	}
	TreeNode *sortedListToBST(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head)
			return NULL;
		vector<int> list;
		while(head)
		{
			list.push_back(head->val);
			head = head->next;
		}
		return genTree(list, 0, list.size()-1);
	}
};