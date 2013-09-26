// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
void treeToDoublyList(Node *p, Node *& prev, Node *& head) {
    if(!p)
        return;
    treeToDoublyList(p->left, prev, head);
    p->left = prev;
    if(prev)
        prev->right = p;
    else
        head = p;
    Node* right = p->right;
    head->left = p;
    p->right = head;
    prev = p;
    treeToDoublyList(right, prev, head);
    
}
int main() {
    Node* prev = NULL;
    Node* head = NULL;
    Node* root;
    treeToDoublyList(root, prev, head);
    return 0;
}