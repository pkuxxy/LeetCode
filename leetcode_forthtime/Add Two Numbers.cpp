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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* head = NULL;
        ListNode* pre = NULL;
        int sum = 0;
        int carry = 0;
        while(l1 || l2)
        {
            sum = carry;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
                
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            ListNode* cur = new ListNode(sum%10);
            if(!head)
                head = cur;
            if(pre)
                pre->next = cur;
            pre = cur;
        }
        if(carry)
            pre->next = new ListNode(carry);
        return head;
    }
};