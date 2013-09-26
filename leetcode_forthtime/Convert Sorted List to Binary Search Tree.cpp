/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* helper(ListNode*& head, int s, int e)
    {
        if(s > e)
            return NULL;
        int mid = s + (e-s)/2;
        TreeNode* left = helper(head, s, mid-1);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = helper(head, mid+1, e);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            len++;
            tmp = tmp->next;
        }
        return helper(head, 0, len-1);
    }
};