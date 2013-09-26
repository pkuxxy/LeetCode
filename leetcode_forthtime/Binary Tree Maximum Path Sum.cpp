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
    int dfs(TreeNode* root, int& ret)
    {
        if(!root)
            return 0;
        int l = dfs(root->left, ret);
        int r = dfs(root->right, ret);
        int sum = root->val + max(0, l) + max(0, r);
        ret = max(ret, sum);
        return root->val + max(l, max(0, r));
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};