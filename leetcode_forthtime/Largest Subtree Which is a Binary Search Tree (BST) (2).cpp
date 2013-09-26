// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int findLargestBSTSubtree(BinaryTree* root, int& min, int& max, int& maxNodes, BinaryTree*& largest)
{
    if(!root)
        return 0;
    bool isbst = true;
    int leftNodes = findLargestBSTSubtree(root->left, min, max, maxNodes, largest);
    int curMin = (leftNodes == 0)? root->val:min;
    if(leftNodes == -1 || (leftNodes != 0 && root->val >= max))
        isbst = false;
    int rightNodes = findLargestBSTSubtree(root->right, min, max, maxNodes, largest);
    int curMax = (rightNodes == 0)?root->val:max;
    if(rightNodes == -1 || (rightNodes != 0 && root->val <= min))
        isbst = false;
    if(isbst)
    {
        min = curMin;
        max = curMax;
        int totalNodes = 1+leftNodes + rightNodes;
        if(totalNodes > maxNodes)
        {
            maxNodes = totalNodes;
            largest = root;
        }
    }
    else
        return -1;
}
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    
    
    return 0;
}