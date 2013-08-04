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
    void traverse(TreeNode* root, TreeNode*& pre, TreeNode*& first, TreeNode*& second)
    {
        if(!root)
            return;
        traverse(root->left, pre, first, second);
        if(pre && pre->val > root->val)
        {
            if(!first)
                first = pre;
            second = root;
        }
        pre = root;
        traverse(root->right, pre, first, second);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* pre = NULL;
        traverse(root, pre,first, second);
        if(first && second)
        {
            swap(first->val, second->val);
        }
    }
};