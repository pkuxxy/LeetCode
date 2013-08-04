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
        TreeLinkNode* pre = NULL;
        TreeLinkNode* nextNode = NULL;
        while(root)
        {
            if(root->left)
            {
                if(pre)
                    pre->next = root->left;
                pre = root->left;
                if(!nextNode)
                    nextNode = pre;
            }
            if(root->right)
            {
                if(pre)
                    pre->next = root->right;
                pre = root->right;
                if(!nextNode)
                    nextNode = pre;
            }
            root = root->next;
        }
        connect(nextNode);
    }
};