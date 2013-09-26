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
    int ret;
    void dfs(TreeNode* root, int sum)
    {
        if(!root)
            return;
        sum = sum*10+root->val;
        if(!root->left && !root->right)
        {
            ret += sum;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        dfs(root, 0);
        return ret;
    }
};