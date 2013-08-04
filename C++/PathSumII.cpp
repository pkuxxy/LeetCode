#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
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
	bool isLeaf(TreeNode* node)
	{
		if(node->left || node->right)
			return false;
		return true;
	}
	void dfs(TreeNode* root, int sum, vector<int> path)
	{
		if(!root)
			return;
		path.push_back(root->val);
		sum -= root->val;
		if(isLeaf(root))
		{
			if(sum == 0)
				ret.push_back(vector<int>(path));
		}
		else
		{
			dfs(root->left, sum, path);
			dfs(root->right, sum, path);
		}
		path.pop_back();
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		vector<int> path;
		dfs(root, sum, path);
		return ret;
	}
};
int main()
{
	TreeNode root(1);
	int sum = 1;
	Solution sol;
	sol.pathSum(&root, sum);
	getchar();
}