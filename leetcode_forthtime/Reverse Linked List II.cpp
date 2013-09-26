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
        if(!head || !head->next)
            return head;
        ListNode* pretail = NULL;
        ListNode* curtail = NULL;
        ListNode* preNode = NULL;
        ListNode* curNode = head;
        for(int i = 1; i <= n; i++)
        {
            if(i == m-1)
                pretail = curNode;
            else if(i == m)
                curtail = curNode;
            if(i >= m)
            {
                ListNode* next = curNode->next;
                curNode->next = preNode;
                preNode = curNode;
                curNode = next;
            }
            else
                curNode = curNode->next;
        }
        if(pretail)
            pretail->next = preNode;
        else
            head = preNode;
        curtail->next = curNode;
        return head;
    }
};