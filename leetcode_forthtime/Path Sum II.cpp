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
    int sum;
    void dfs(TreeNode* root, vector<int>& path)
    {
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            int cur = 0;
            for(int i = 0; i < path.size(); i++)
                cur += path[i];
            if(cur == sum)
                ret.push_back(path);
        }
        
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!root)
            return ret;
        vector<int> path;
        this->sum = sum;
        dfs(root, path);
        return ret;
    }
};