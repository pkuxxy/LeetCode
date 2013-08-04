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
        int count = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return head;
        int len = getLen(head);
        k %= len;
        if(!len || !k)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(k--)
        {
            p2 = p2->next;
        }
        while(p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* newhead = p1->next;
        p1->next = p2->next;
        p2->next = head;
        return newhead;
    }
};