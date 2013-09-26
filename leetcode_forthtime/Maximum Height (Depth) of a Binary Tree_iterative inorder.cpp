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
    int maxd = 0;
    int level = 0;
    BinaryTree* cur = root;
    while(!s.empty() || cur)
    {
        if(cur)
        {
            s.push(cur);
            level++;
            cur = cur->left;
        }
        else
        {
            cur = s.top();
            level--;
            cur = cur->right;
        }
        maxd = max(maxd, level);
    }
    return maxd;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}