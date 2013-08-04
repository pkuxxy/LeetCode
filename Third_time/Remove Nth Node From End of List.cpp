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
        if(!head && n <= 0)
            return head;
        ListNode* pre = NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(n--)
            p2 = p2->next;
        while(p2)
        {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(pre)
            pre->next = p1->next;
        else
            head = p1->next;
        free(p1);
        return head;
    }
};