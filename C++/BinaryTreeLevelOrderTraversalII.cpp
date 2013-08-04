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
	vector<vector<int>> ret;
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		if(!root)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		int pre = 1;
		int next = 0;
		vector<int> list;
		while(!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();
			pre--;
			list.push_back(node->val);
			if(node->left)
			{
				q.push(node->left);
				next++;
			}
			if(node->right)
			{
				q.push(node->right);
				next++;
			}
			if(pre == 0)
			{
				pre = next;
				next = 0;
				ret.push_back(list);
				list.clear();
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int main()
{
	TreeNode root(1);
	TreeNode l(2);
	root.left = &l;
	Solution sol;
	sol.levelOrderBottom(&root);
	getchar();
}