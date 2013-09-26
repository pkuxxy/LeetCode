// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include<stack>
using namespace std;
int maxDepthIterative(BinaryTree *root) {
    if(!root)
        return 0;
    stack<BinaryTree*> s;
    s.push(root);
    int maxd = 0;
    BinaryTree* pre = NULL;
    while(!s.empty())
    {
        BinaryTree* cur = s.top();
        if(!pre || pre->left == cur || pre->right == cur)
        {
            if(cur->left)
                s.push(cur->left);
            else if(cur->right)
                s.push(cur->right);
        }
        else if(cur->left == pre)
        {
            if(cur->right)
                s.push(cur->right);
        }
        else
        {
            s.pop();
        }
        pre = cur;
        maxd = max(s.size(),maxd);
    }
    return maxd;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}