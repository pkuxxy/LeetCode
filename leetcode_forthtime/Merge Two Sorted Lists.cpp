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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* nh = NULL;
        ListNode* pre = NULL;
        ListNode** next = NULL;
        while(l1 || l2)
        {
            next = &l1;
            if(!l1 || (l2 && l1->val > l2->val))
                next =  &l2;
            if(!nh)
            {
                nh = *next;
            }
            if(pre)
                pre->next = *next;
            pre = *next;
            *next = (*next)->next;
        }
        return nh;
    }
};