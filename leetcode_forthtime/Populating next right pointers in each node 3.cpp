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
void connect(Node* head)
{
    if(!head)
        return;
    while(head)
    {
        Node* nextLevel = NULL;
        Node* pre = NULL;
        for(; head; head= head->next)
        {
            if(head->left)
            {
                if(!nextLevel)
                    nextLevel = head->left;
                if(pre)
                    pre->next = head->left;
                pre = head->left;
            }
            if(head->right)
            {
                if(!nextLevel)
                    nextLevel = head->right;
                if(pre)
                    pre->next = head->right;
                pre = head->right;
            }
        }
        head = nextLevel;
    }
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}