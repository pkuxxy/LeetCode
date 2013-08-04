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
    void dfs(TreeNode* root,vector<int>& path)
    {
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            int sum = 0;
            for(int i = 0; i < path.size(); i++)
            {
                sum *= 10;
                sum += path[i];
            }
            ret += sum;
        }
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        vector<int> path;
        dfs(root, path);
        return ret;
    }
};