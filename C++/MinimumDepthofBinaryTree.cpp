#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
			return 0;
		int ll = minDepth(root->left);
		int rl = minDepth(root->right);
		if(ll && rl)
			return 1 + min(ll, rl);
		else if(ll || rl)
			return 1 + ll + rl;
		else
			return 1;
    }
};