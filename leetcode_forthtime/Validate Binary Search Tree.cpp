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
    bool check(TreeNode* root, int min, int max)
    {
        if(!root)
            return true;
        if(root->val < min || root->val > max)
            return false;
        return check(root->left, min, root->val-1) && check(root->right, root->val+1, max);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root, INT_MIN, INT_MAX);
    }
};