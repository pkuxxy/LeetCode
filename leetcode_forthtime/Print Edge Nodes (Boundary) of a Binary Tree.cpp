// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
void printLeftEdges(BinaryTree* root, bool print)
{
    if(!root)
        return;
    if(print || (!root->left && !root->right))
        cout<<root->val<<endl;
    printLeftEdges(root->left, print);
    printLeftEdges(root->right, (print && !root->left? true: false));
}
void printRightEdges(BinaryTree* root, bool print)
{
    if(!root)
        return;
    printRightEdges(root->left, (print && !root->right ? true:false));
    printRightEdges(root->right, print);
    if(print || (!root->left && !root->right))
        cout<<root->val<<endl;
}
void printOuterEdges(BinaryTree* root)
{
    if(!root)
        return;
    printLeftEdges(root->left, true);
    printRightEdges(root->right, true);
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}