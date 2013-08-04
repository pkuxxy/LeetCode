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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return head;
        ListNode* nh = new ListNode(0);
        nh->next = head;
        ListNode* pre = nh;
        ListNode* cur = nh;
        ListNode* tail = nh;
        while(n--)
        {
            if(m > 0)
            {
                m--;
                pre = cur;
                cur = cur->next;
            }
            tail = tail->next;
        }
        while(cur != tail)
        {
            pre->next = cur->next;
            cur->next = tail->next;
            tail->next = cur;
            cur = pre->next;
        }
        head = nh->next;
        free(nh);
        return head;
    }
};