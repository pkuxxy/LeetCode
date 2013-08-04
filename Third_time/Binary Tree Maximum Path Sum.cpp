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
    int maxsum;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int lm = dfs(root->left);
        int rm = dfs(root->right);
        int sum = root->val+max(0,lm)+max(0,rm);
        maxsum = max(sum,maxsum);
        return root->val+max(0, max(lm,rm));
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxsum = INT_MIN;
        dfs(root);
        return maxsum;
        
    }
};