// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <stack>
using namespace std;
void inorderTraverse(TreeNode* root)
{
    if(!root)
        return;
    stack<TreeNode*> s;
    //s.push(root);
    TreeNode* cur = root;
    while(!s.empty() || cur)
    {
        if(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            s.pop();
            cout<<cur->val<<endl;
            cur = cur->right;
        }
    }
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}