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
    int getLen(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return NULL;
        int len = getLen(head);
        k %= len;
        if(!k)
            return head;
        ListNode* tail = head;
        while(k--)
            tail = tail->next;
        ListNode* pre = head;
        while(tail->next)
        {
            pre = pre->next;
            tail = tail->next;
        }
        ListNode* nh = pre->next;
        pre->next = NULL;
        tail->next = head;
        return nh;
    }
};