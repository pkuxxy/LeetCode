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
	TreeNode* preorder(TreeNode* root)
	{
		if(!root)
			return root;
		TreeNode* rightSub = root->right;
		root->right = preorder(root->left);
		root->left = NULL;
		TreeNode* rm = rightMost(root);
		rm->right = preorder(rightSub);
		return root;
	}
	void flatten(TreeNode *root) {
		root = preorder(root);
	}
	TreeNode* rightMost(TreeNode* root)
	{
		if(!root)
			return root;
		while(root->right)
		{
			root = root->right;
		}
		return root;
	}
};