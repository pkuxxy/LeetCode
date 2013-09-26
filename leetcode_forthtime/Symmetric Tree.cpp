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
    bool solve(TreeNode* p1, TreeNode* p2)
    {
        if(!p1 && !p2)
            return true;
        if(!p1 || !p2 || p1->val != p2->val)
            return false;
        return solve(p1->left, p2->right) && solve(p1->right, p2->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return true;
        return solve(root->left, root->right);
    }
};