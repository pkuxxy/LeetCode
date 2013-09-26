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
    vector<TreeNode*> gen(int s, int e)
    {
        vector<TreeNode*> ret;
        if(s > e)
        {
            ret.push_back(NULL);
            return ret;
        }
        for(int i = s; i <= e; i++)
        {
            vector<TreeNode*> left = gen(s, i-1);
        vector<TreeNode*> right = gen(i+1, e);
        for(int j = 0; j < left.size(); j++)
        {
            for(int k = 0; k < right.size(); k++)
            {
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ret.push_back(root);
            }
        }
        }
        
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return gen(1, n);
    }
};