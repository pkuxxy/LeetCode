// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
BinaryTree* getMaxDepthNode(BinarTree* root, int& dep)
{
    if(!root)
    {
        dep = 0;
        return root;
    }
    if(!root->left && !root->right)
    {
        dep = 1;
        return root;
    }
    int left;
    int right;
    BinaryTree* lc = getMaxDepthNode(root->left, left);
    BinaryTree* rc = getMaxDepthNode(root->right, right);
    dep = 1+max(left, right);
    return left>right? lc:rc;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}