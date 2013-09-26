// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <stack>
using namespace std;
void postorderTraverse(TreeNode* root)
{
    if(!root)
        return;
    stack<TreeNode*> s;
    TreeNode* pre = NULL;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* cur = s.top();
        if(!pre || pre->left == cur || pre->right == cur)
        {
            if(cur->left)
                s.push(cur->left);
            else if(cur->right)
                s.push(cur->right);
            else
            {
                cout<<cur->val<<endl;
                s.pop();
            }
        }
        else if(cur->left == pre)
        {
            if(cur->right)
                s.push(cur->right);
            else
            {
                cout<<cur->val<<endl;
                s.pop();
            }
        }
        else
        {
            cout<<cur->val<<endl;
            s.pop();
        }
        pre = cur;
    }
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}