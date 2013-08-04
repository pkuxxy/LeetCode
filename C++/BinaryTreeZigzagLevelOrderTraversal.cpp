#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int> > ret;
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		if(!root)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		int pre = 1;
		int next = 0;
		bool direct = false;
		vector<int> list;
		while(!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			list.push_back(cur->val);
			pre--;
			if(cur->left)
			{
				q.push(cur->left);
				next++;
			}
			if(cur->right)
			{
				q.push(cur->right);
				next++;
			}

			if(pre == 0)
			{
				pre = next;
				next = 0;
				if(direct)
					reverse(list.begin(), list.end());
				ret.push_back(list);
				list.clear();
				direct = !direct;
			}
		}
		return ret;
	}
};