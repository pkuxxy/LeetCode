// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int findLargestBST(BinaryTree* root, int min, int max, int& maxNodes, BinaryTree* largest, BinaryTree* child)
{
    if(!root)
        return 0;
    if(root->val > min && root->val < max)
    {
        int leftNodes = findLargestBST(root->left, min, root->val, maxNodes, largest, child);
        BinaryTree* leftchild = (leftNodes == 0) ? NULL:child;
        int rightNodes = findLargestBST(root->right, root->val, max, maxNodes, largest, child);
        BinaryTree* rightchild = (rightNodes == 0) ? NULL:child;
        BinaryTree* parent = new BinaryTree(root->val);
        parent->left = leftchild;
        parent->right = rightchild;
        int totalNodes = leftNodes + rightNodes +1;
        if(totalNodes > maxNodes)
        {
            maxNodes = totalNodes;
            largest = parent;
        }
        child = parent;
        return totalNodes;
    }
    else
    {
        findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largest, child);
        return 0;
    }
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}