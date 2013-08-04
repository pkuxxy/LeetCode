#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return true;
		queue<TreeNode*> lq;
		queue<TreeNode*> rq;
		lq.push(root->left);
		rq.push(root->right);
		while(!lq.empty() && !rq.empty())
		{
			TreeNode* ln = lq.front();
			TreeNode* rn = rq.front();
			lq.pop();
			rq.pop();
			if(ln == NULL && rn == NULL)
				continue;
			else if(ln == NULL || rn == NULL)
				return false;
			if(ln->val != rn->val)
				return false;
			lq.push(ln->left);
			rq.push(rn->right);
			lq.push(ln->right);
			rq.push(rn->left);
		}
		if(lq.empty() && rq.empty())
			return true;
		return false;
	}
};