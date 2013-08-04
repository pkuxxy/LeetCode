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
	int find(vector<int> list, int s, int e, int target)
	{
		for(int i = s; i <= e; i++)
		{
			if(list[i] == target)
				return i;
		}
		return -1;
	}
	TreeNode* build(vector<int>& preorder, int s1, int e1, vector<int>&inorder, int s2, int e2)
	{
		if(s1 > e1)
			return NULL;
		TreeNode* root = new TreeNode(preorder[s1]);
		int index = find(inorder, s2, e2, root->val);
		root->left = build(preorder, s1+1, s1+(index-s2), inorder, s2, index-1);
		root->right = build(preorder, s1+(index-s2)+1, e1, inorder, index+1, e2);
		return root;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int len = preorder.size();
		return build(preorder, 0, len-1, inorder, 0, len-1);
	}
};