// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include<deque>
using namespace std;
void maxSlidingWindow(int A[], int n, int w, int B[]) {
    deque<int> Q;
    for(int i = 0; i < w; i++)
    {
        while(!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for(int i = w; i < n; i++)
    {
        B[i-w] = A[Q.front()];
        while(!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        while(!Q.empty() && Q.front() <= i-w)
            Q.pop_front();
        Q.push_back(i);
    }
    B[n-w] = A[Q.front()];
}
int main() {
    int a[] = {1,  3,  -1, -3,  5,  3,  6,  7};
    int n = 8;
    int b[8];
    maxSlidingWindow(a, n, 3, b);
    for(int i = 0; i < 6; i++)
    {
        cout<<b[i]<<endl;
    }
    
    return 0;
}