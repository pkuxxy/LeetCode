#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!root)
			return;
		queue<TreeLinkNode*> q;
		q.push(root);
		int preCount = 1;
		int nextCount = 0;
		TreeLinkNode* pre = NULL;
		while(!q.empty())
		{
			TreeLinkNode* cur = q.front();
			q.pop();
			preCount--;
			if(pre)
				pre->next = cur;
			if(cur->left)
			{
				nextCount++;
				q.push(cur->left);
			}
			if(cur->right)
			{
				nextCount++;
				q.push(cur->right);
			}
			pre = cur;
			if(preCount == 0)
			{
				preCount = nextCount;
				nextCount = 0;
				pre->next = NULL;
				pre = NULL;
			}
		}
	}
};