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
    int mind;
    void dfs(TreeNode* root, int dep)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            mind = min(mind, dep);
        }
        dfs(root->left, dep+1);
        dfs(root->right, dep+1);
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return 0;
        mind = INT_MAX;
        dfs(root, 1);
        return mind;
    }
};