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
    vector<vector<int> > ret;
    void dfs(TreeNode* root, int sum, vector<int>& path)
    {
        if(!root)
            return;
        sum -= root->val;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum == 0)
                ret.push_back(path);
        }
        dfs(root->left, sum, path);
        dfs(root->right, sum, path);
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        vector<int> path;
        dfs(root, sum, path);
        return ret;
    }
};