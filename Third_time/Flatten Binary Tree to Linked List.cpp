/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rightmost(TreeNode* root)
    {
        if(!root)
            return root;
        while(root->right)
        {
            root = root->right;
        }
        return root;
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return;
        flatten(root->left);
        flatten(root->right);
	if(!root->left)
		return;
        TreeNode* r = root->right;
        TreeNode* rm = rightmost(root->left);
        root->right = root->left;
        root->left = NULL;
        rm->right = r;
    }
};