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
    void dfs(TreeNode* root, vector<int>& path, int sum)
    {
        if(!root)
            return;
        path.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right)
        {
            if(!sum)
                ret.push_back(path);
        }
        dfs(root->left, path, sum);
        dfs(root->right, path, sum);
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        vector<int> path;
        dfs(root, path, sum);
        return ret;
    }
};