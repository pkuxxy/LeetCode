// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int findLargestBST(BinaryTree* p, int& minv, int& maxv, int& maxNodes, BinaryTree*& largestBST)
{
    if(!p)
        return 0;
    bool isBST = true;
    int left = findLargestBST(p->left, minv, maxv, maxNodes, largestBST);
    int curMin = (left == 0) ? p->val:minv;
    if(left == -1 || (left != 0 && p->val <= maxv))
        isBST = false;
    int right = findLargestBST(p->right, minv, maxv, maxNodes, largestBST);
    int curMax = (right == 0) ? p->val:maxv;
    if(right == -1 || (right != 0 && p->val >= minv))
        isBST = false;
    if(isBST)
    {
        minv = curMin;
        maxv = curMax;
        int total = left+right+1;
        if(total > maxNodes)
        {
            maxNodes = total;
            largestBST = p;
        }
        return total;
    }
    else
        return -1;
}
int main() {
    BinaryTree* root;
    int minv;
    int maxv;
    int maxNodes;
    BinaryTree* largestBST = NULL;
    cout<<findLargestBST(root, minv, maxv, maxNodes, largestBST);
    return 0;
}