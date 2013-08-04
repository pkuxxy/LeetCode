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
        ListNode* head = new ListNode(0);
        ListNode* pre = head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        if(l1)
            pre->next = l1;
        else if(l2)
            pre->next = l2;
        pre = head;
        head = head->next;
        free(pre);
        return head;     
    }
};