// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
bool isBSTInorderHelper(BinaryTree* root, int& prev)
{
    if(!root)
        return true;
    if(isBSTInorderHelper(root->left, prev))
    {
        if(!(root->val > prev))
            return false;
        prev = root->val;
        return isBSTInorderHelper(root->right, prev);
    }
    else
        return false;
}
bool isBST(BinaryTree* root)
{
    int prev = INT_MIN;
    return isBSTInorderHelper(root, prev);
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}