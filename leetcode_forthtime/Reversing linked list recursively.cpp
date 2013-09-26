// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
void reverse(Node* head)
{
    if(!head)
        return;
    Node* rest = head->next;
    if(!rest)
        return;
    reverse(rest);
    head->next->next = head;
    head->next = NULL;
    head = rest;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}