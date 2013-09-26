/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root || !root->left || !root->right)
            return;
        TreeLinkNode* tmp = root;
        while(root)
        {
            TreeLinkNode* rightsib = root->next?root->next->left:NULL;
            root->left->next = root->right;
            root->right->next = rightsib;
            root = root->next;
        }
        connect(tmp->left);
    }
};