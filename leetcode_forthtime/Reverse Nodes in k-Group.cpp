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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || k <= 1)
            return head;
        ListNode* nh = new ListNode(0);
        nh->next = head;
        ListNode* pre = nh;
        while(true)
        {
            int tmp = k-1;
            ListNode* nextpre = pre->next;
            ListNode* tail = pre->next;
            while(tail && tmp--)
                tail = tail->next;
            if(!tail)
                break;
            while(pre->next != tail)
            {
                ListNode* cur = pre->next;
                pre->next = cur->next;
                cur->next = tail->next;
                tail->next = cur;
            }
            pre = nextpre;
        }
        head = nh->next;
        free(nh);
        return head;
    }
};