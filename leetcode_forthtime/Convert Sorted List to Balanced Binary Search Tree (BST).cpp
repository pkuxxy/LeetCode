// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int listLen(ListNode* head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}
BinaryTree* sortedListToBST(ListNode *& list, int start, int end) {
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    BinaryTree* left = sortedListToBST(list, start, mid-1);
    BinaryTree* parent = new BinaryTree(list->val);
    parent->left = left;
    list = list->next;
    parent->right = sortedListToBST(list, mid+1, end);
    return parent;
}
int main() {
    ListNode* head;
    int len = listLen(head);
    sortedListToBST(head, 0, len-1);
    
    return 0;
}