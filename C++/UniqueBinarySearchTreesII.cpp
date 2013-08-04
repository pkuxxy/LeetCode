#include<iostream>
#include<vector>
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
	vector<TreeNode *> gen(int s, int e)
	{
		vector<TreeNode *> ret;
		if(s > e)
		{
			ret.push_back(NULL);
			return ret;
		}
		for(int i = s; i <= e; i++)
		{
			vector<TreeNode*> lefts = gen(s,i-1);
			vector<TreeNode*> rights = gen(i+1, e);
			for(int k = 0; k < lefts.size(); k++)
			{
				for(int j = 0; j < rights.size(); j++)
				{
					TreeNode* root = new TreeNode(i);
					root->left = lefts[k];
					root->right = rights[j];
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
	vector<TreeNode *> generateTrees(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return gen(1, n);
	}
};