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
    void inorder(TreeNode* cur, TreeNode*& pre, TreeNode*& first, TreeNode*& second)
    {
        if(!cur)
            return;
        inorder(cur->left, pre, first, second);
        if(pre && pre->val > cur->val)
        {
            if(!first)
                first = pre;
            second = cur;
        }
        pre = cur;
        inorder(cur->right, pre, first, second);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* pre = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        inorder(root, pre, first, second);
        swap(first->val, second->val);
    }
};