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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return false;
        int diff = sum - root->val;
        if(!root->left && !root->right)
            return diff == 0;
        return hasPathSum(root->left, diff) || hasPathSum(root->right, diff);
    }
};