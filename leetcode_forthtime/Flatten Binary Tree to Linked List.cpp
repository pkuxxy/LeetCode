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
            return NULL;
        while(root->right)
            root = root->right;
        return root;
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return;
        TreeNode* right = root->right;
        flatten(root->left);
        root->right = root->left;
        root->left = NULL;
        TreeNode* rm = rightmost(root);
        rm->right = right;
        flatten(right);
    }
};