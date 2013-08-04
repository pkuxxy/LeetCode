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
    bool check(TreeNode* n1, TreeNode* n2)
    {
        if(!n1 && !n2)
        return true;
        else if(!n1 || !n2)
        return false;
        if(n1->val != n2->val)
        return false;
        return check(n1->left, n2->right) && check(n1->right, n2->left);
        
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return true;
        return check(root->left, root->right);
    }
};