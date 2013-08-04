/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur)
        {
            ListNode* next = cur->next;
            if(pre->val == cur->val)
            {
                pre->next = next;
                free(cur);
            }
            else
                pre = cur;
            cur = next;
        }
        return head;
    }
};