/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<math.h>
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return 0;
        stack<TreeNode*> s;
        s.push(root);
        int maxd = 1;
        TreeNode* pre = NULL;
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            if(!pre || pre->left == cur || pre->right == cur)
            {
                if(cur->left)
                    s.push(cur->left);
                else if(cur->right)
                    s.push(cur->right);
                else
                    s.pop();
            }
            else if(cur->left == pre)
            {
                if(cur->right)
                    s.push(cur->right);
                else
                    s.pop();
            }
            else
                s.pop();
            pre = cur;
            maxd = max(maxd, (int)s.size());
        }
        return maxd;
    }
};