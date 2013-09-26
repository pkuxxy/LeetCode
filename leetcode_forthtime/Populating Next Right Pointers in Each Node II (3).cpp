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
        if(!root)
            return;
        TreeLinkNode* nextroot = NULL;
        TreeLinkNode* pre = NULL;
        while(root)
        {
            if(root->left)
            {
                if(!nextroot)
                    nextroot = root->left;
                if(pre)
                    pre->next = root->left;
                pre = root->left;
            }
            if(root->right)
            {
                if(!nextroot)
                    nextroot = root->right;
                if(pre)
                    pre->next = root->right;
                pre = root->right;
            }
            root = root->next;
        }
        connect(nextroot);
    }
};