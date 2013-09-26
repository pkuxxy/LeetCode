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
    ListNode* merge2lists(ListNode* l1, ListNode* l2)
    {
        if(!l1 || !l2)
            return (l1)?l1:l2;
        ListNode* head = l1;
        if(l1->val < l2->val)
        {
            ListNode* head = l1;
            head->next = merge2lists(l1->next, l2);
            return head;
        }
        else
        {
            ListNode* head = l2;
            head->next = merge2lists(l1, l2->next);
            return head;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = lists.size();
        if(!len)
            return NULL;
        while(len > 1)
        {
            int half = len/2;
            for(int i = 0; i < half; i++)
            {
                lists[i] = merge2lists(lists[i], lists[i+half+len%2]);
            }
            len = half+len%2;
        }
        return lists[0];
    }
};