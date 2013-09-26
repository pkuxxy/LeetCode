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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || n <= 0)
            return head;
        ListNode* pre = head;
        ListNode* cur = head;
        while(n-- && cur->next)
            cur = cur->next;
        if(n >= 0)
        {
            head = head->next;
            free(pre);
            return head;
        }  
        while(cur->next)
        {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* next = pre->next;
        pre->next = next->next;
        free(next);
        return head;
    }
};