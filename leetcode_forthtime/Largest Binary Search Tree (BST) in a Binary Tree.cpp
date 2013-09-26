// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int findLargest(BinaryTree* p, int min, int max, int& maxNodes, BinaryTree*& largest, Binary*& child);
{
    if(!p)
        return 0;
    if(min < p->val && p->val < max)
    {
        int leftNodes = findLargest(p->left, min, p->val, maxNodes, largest, child);
        BinaryTree* left = (leftNodes == 0) ? NULL:child;
        int rightNodes = findLargest(p->right, p->val, max, maxNodes, largest, child);
        BinaryTree* right = (rightNodes == 0) ? NULL:child;
        BinaryTree* parent = new BinaryTree(p->val);
        parent->left = left;
        parent->right = right;
        int total = leftNodes + rightNodes +1;
        if(total > maxNodes)
        {
            maxNodes = total;
            largest = parent;
        }
        child = parent;
    }
    else
    {
        findLargest(p, INT_MIN, INT_MAX, maxNodes, largest, child);
        return 0;
    }
}
int main() {
    BinaryTree* root;
    BinaryTree* largest = NULL;
    BinaryTree* child = NULL;
    int maxNodes = INT_MIN;
    
    findLargest(root, INT_MIN, INT_MAX,maxNodes, largest, child);
    
    
    return 0;
}