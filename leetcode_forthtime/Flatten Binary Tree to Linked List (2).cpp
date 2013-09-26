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
    void dfs(TreeNode* root, TreeNode*& pre)
    {
        if(!root)
            return;
        TreeNode* left = root->left;
        root->left = NULL;
        TreeNode* right = root->right;
        root->right = NULL;
        if(pre)
        {
            pre->right = root;
            pre = pre->right;
        }
        else
            pre = root;
        dfs(left, pre);
        dfs(right, pre);
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* pre = NULL;
        dfs(root, pre);
    }
};