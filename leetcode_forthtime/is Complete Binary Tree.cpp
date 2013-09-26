// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
bool isComplete(TreeNode* root)
{
    if(!root)
        return true;
    queue<TreeNode*> q;
    q.push(root);
    bool leftmost = false;
    while(!q.empty())
    {
        TreeNode* cur = q.front();
        q.pop();
        if(cur->left)
        {
            if(leftmost)
                return false;
            q.push(cur->left);
        }
        else
            leftmost = true;
        if(cur->right)
        {
            if(leftmost)
                return false;
            q.push(cur->right);
        }
        else
            leftmost = true;
    }
    return true;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}