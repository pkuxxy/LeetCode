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
        ListNode* prehead = NULL;
        ListNode* pretail = NULL;
        ListNode* posthead = NULL;
        ListNode* posttail = NULL;
        while(head)
        {
            if(head->val < x)
            {
                if(!prehead)
                    prehead = head;
                if(pretail)
                    pretail->next = head;
                pretail = head;
            }
            else
            {
                if(!posthead)
                    posthead = head;
                if(posttail)
                    posttail->next = head;
                posttail = head;
            }
            head = head->next;
        }
        if(pretail)
            pretail->next = posthead;
        if(posttail)
            posttail->next = NULL;
        return prehead?prehead:posthead;
    }
};