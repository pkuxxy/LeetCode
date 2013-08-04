#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sum;
	bool isLeaf(TreeNode* node)
	{
		return !(node->left || node->right);
	}
	int genNum(vector<int>& list)
	{
		int s = 0;
		for(int i = 0; i < list.size(); i++)
		{
			s *= 10;
			s += list[i];
		}
		return s;
	}
	void dfs(TreeNode* root, vector<int>& list)
	{
		if(!root)
			return;
		list.push_back(root->val);
		if(isLeaf(root))
		{
			sum += genNum(list);
		}
		else
		{
			dfs(root->left, list);
			dfs(root->right, list);
		}
		list.pop_back();
	}
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sum = 0;
		vector<int> list;
		dfs(root, list);
		return sum;

	}
};
int main()
{
	TreeNode root(9);
	Solution sol;
	cout<<sol.sumNumbers(&root);
	getchar();
}