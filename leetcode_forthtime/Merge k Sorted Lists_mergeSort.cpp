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
        ListNode* head = NULL;
        ListNode* pre = NULL;
        ListNode** next = NULL;
        while(l1 || l2)
        {
            next = &l1;
            if(!l1 || (l2 && l1->val > l2->val))
                next = &l2;
            if(!head)
                head = *next;
            if(pre)
                pre->next = *next;
            pre = *next;
            *next = (*next)->next;
        }
        return head;
    }
    ListNode* merge(vector<ListNode*>& lists, int s, int e)
    {
        if(s >= e)
            return lists[s];
        int mid = s+(e-s)/2;
        ListNode* l1 = merge(lists, s, mid);
        ListNode* l2 = merge(lists, mid+1, e);
        return merge2lists(l1, l2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = lists.size();
        if(!len)
            return NULL;
        return merge(lists, 0, len-1);
    }
};