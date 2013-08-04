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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(!left || !right)
            return left+right+1;
        else
            return min(left, right) + 1;
    }
};