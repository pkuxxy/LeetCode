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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!root)
            return ret;
        stack<TreeNode*> pre;
        stack<TreeNode*> next;
        pre.push(root);
        vector<int> row;
        bool ltor = true;
        while(!pre.empty())
        {
            TreeNode* cur = pre.top();
            pre.pop();
            row.push_back(cur->val);
            if(ltor)
            {
                if(cur->left)
                    next.push(cur->left);
                if(cur->right)
                    next.push(cur->right);
            }
            else
            {
                if(cur->right)
                    next.push(cur->right);
                if(cur->left)
                    next.push(cur->left);
            }
            if(pre.empty())
            {
                ret.push_back(row);
                row.clear();
                swap(pre, next);
                ltor = !ltor;
            }
        }
        return ret;
    }
};