// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

struct Node {
  Node* left;
  Node* right;
  Node* next;
};
void completeTreeConnect(Node* head)
{
    if(!head || !head->left || !head->right)
        return;
    Node* p = head;
    Node* next;
    while(p)
    {
        if(p->next)
            next = p->next->left;
        else
            next = NULL;
        p->left->next = p->right;
        p->right->next = next;
        p = p->next;
    }
    completeTreeConnect(head->left);
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}