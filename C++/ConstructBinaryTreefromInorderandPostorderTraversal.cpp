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
	TreeNode* build(vector<int>& inorder, int s1, int e1, vector<int>&postorder, int s2, int e2)
	{
		if(s1 > e1)
			return NULL;
		TreeNode* root = new TreeNode(postorder[e2]);
		int index = find(inorder, s1, e1, root->val);
		root->left = build(inorder, s1, index-1, postorder, s2, s2 + (index-s1)-1);
		root->right = build(inorder, index+1, e1, postorder, s2 + (index-s1), e2-1);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = inorder.size();
		return build(inorder, 0, len-1, postorder, 0, len-1);
	}
};