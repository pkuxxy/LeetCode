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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* nh = NULL;
        ListNode* pre = NULL;
        while(head)
        {
            int count = 1;
            while(head->next && head->val == head->next->val)
            {
                count++;
                head = head->next;
            }
            if(count == 1)
            {
                if(!nh)
                    nh = head;
                if(pre)
                {
                    pre->next = head;
                }
                pre = head;
            }
            head = head->next;
        }
        if(pre)
            pre->next = NULL;
        return nh;
    }
};