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
    if(!head)
        return;
    if(head->left)
    {
        head->left->next = head->right;
    }
    if(head->right)
        head->right->next = head->next ? head->next->left:NULL;
    completeTreeConnect(head->left);
    completeTreeConnect(head->right);
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}