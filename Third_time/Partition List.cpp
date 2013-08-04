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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return head;
        ListNode* newhead = new ListNode(0);
        ListNode* pre = newhead;
        pre->next = head;
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        ListNode* end = tail;
        while(head != end)
        {
            if(head->val >= x)
            {
                pre->next = head->next;
                tail->next = head;
                head->next = NULL;
                tail = head;
                head = pre->next;
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }
        if(head != tail && head->val >= x)
        {
            pre->next = head->next;
            tail->next = head;
            head->next = NULL;
        }
        head = newhead->next;
        free(newhead);
        return head;
    }
};