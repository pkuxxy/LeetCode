// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
BinaryTree* getNext(BinaryTree* root)
{
    if(!root)
        return NULL;
    if(root->right)
        return leftmost(root->right);
    while(root->parent)
    {
        if(root->parent->left == root)
            return root->parent;
        root = root->parent;
    }
    return NULL;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}