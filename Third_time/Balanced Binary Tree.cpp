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
    bool check(TreeNode* root, int& dep)
    {
        if(!root)
        {
            dep = 0;
            return true;
        }
        int left = 0;
        int right = 0;
        if(!check(root->left, left) || !check(root->right, right))
            return false;
        dep = max(left,right)+1;
        return abs(left-right) <= 1;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dep = 0;
        return check(root, dep);
    }
};