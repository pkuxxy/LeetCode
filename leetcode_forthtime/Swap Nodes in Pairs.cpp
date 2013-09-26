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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return NULL;
        ListNode* nh = head;
        if(head && head->next)
            nh = head->next;
        ListNode* pre = NULL;
        while(head && head->next)
        {
            ListNode* next = head->next;
            head->next = next->next;
            next->next = head;
            if(pre)
                pre->next = next;
            pre = head;
            head = pre->next;
        }
        return nh;
    }
};