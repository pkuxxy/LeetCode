#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* genNode(vector<int> &num, int s, int e)
	{
		if(s > e)
			return NULL;
		int mid = (s + e) / 2;
		TreeNode* root = new TreeNode(num[mid]);
		root->left = genNode(num, s, mid-1);
		root->right = genNode(num, mid+1, e);
		return root;
	}
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return genNode(num, 0, num.size()-1);
	}
};