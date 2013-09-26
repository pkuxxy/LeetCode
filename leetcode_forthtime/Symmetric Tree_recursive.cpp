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
    bool helper(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        if(!l || !r || l->val != r->val)
            return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
};