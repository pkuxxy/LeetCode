// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int findKthSmallest(int A[], int m, int B[], int n, int k) {
    if(!A || !B || m <= 0 || n <= 0 || k < 0)
        return 0;
    int i = (int)((double)m/(m+n)*(k-1));
    int j = k-1-i;
    int ai_1 = (i==0)?INT_MIN:A[i-1];
    int bj_1 = (j == 0) ? INT_MIN:B[j-1];
    int ai = (i == m) ? INT_MAX:A[i];
    int bj = (j == n) ? INT_MAX:B[j];
    if(bj_1 <= ai && ai <= bj)
        return ai;
    else if(ai_1 <= bj && bj <= ai)
        return bj;
    else if(ai < bj)
        return findKthSmallest(A+i+1,m-i-1,B, n, k-i-1);
    else
        return findKthSmallest(A, m, B+j+1, n-j-1, k-j-1);
}
int main() {
    int a[] = {1,3,5,7,9};
    int b[] = {2,4,6,8,10};
    cout<<findKthSmallest(a, 5, b, 5, 5);
    
    
    
    return 0;
}