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
    TreeNode* gen(vector<int>& num, int s, int e)
    {
        if(s > e)
        return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = gen(num, s, mid-1);
        root->right = gen(num, mid+1, e);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        return gen(num, 0, len-1);
    }
};