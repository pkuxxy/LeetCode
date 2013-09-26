// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

void printLevel(BinaryTree* root, int level)
{
    if(!root)
        return;
    if(level == 1)
    {
        cout<<root->val<<endl;
    }
    else
    {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}
int maxHeight(BinaryTree* root)
{
    if(!root)
        return 0;
    return 1+max(maxHeight(root->left), maxHeight(root->right));
}
void traverseDFS(BinaryTree* root)
{
    if(!root)
        return;
    int height = maxHeight(root);
    for(int i = 1; i <= height; i++)
        printLevel(root, i);
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}