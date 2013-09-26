/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp
{
    bool operator()(const ListNode* n1, const ListNode* n2)
    {
        return n1->val > n2->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* head = NULL;
        ListNode* pre = NULL;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
                q.push(lists[i]);
        }
        while(!q.empty())
        {
            ListNode* cur = q.top();
            q.pop();
            if(!head)
                head = cur;
            if(pre)
                pre->next = cur;
            pre = cur;
            if(cur->next)
                q.push(cur->next);
        }
        return head;
    }
};