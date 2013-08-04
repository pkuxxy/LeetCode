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
        int val = head->val;
        ListNode** p = &head;
        ListNode* cur = head;
        if(!cur->next || cur->val != cur->next->val)
        {
            p = &cur->next;
            cur = cur->next;
        }
        while(cur)
        {
            if(cur->val != val)
            {
                if(!cur->next || cur->val != cur->next->val)
                {
                    *p = cur;
                    p = &cur->next;
                }
                val = cur->val;
            }
            cur = cur->next;
        }
        *p = NULL;
        return head;
    }
};