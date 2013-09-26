// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include<math.h>
using namespace std;
int sum(int a[], int s, int e)
{
    int total = 0;
    for(int i = s; i <= e; i++)
    {
        total += a[i];
    }
    return total;
}
int partition(int a[], int n, int k)
{
    if(k == 1)
        return sum(a, 0, n-1);
    if(n == 1)
        return a[0];
    int minv = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        minv = min(minv, max(partition(a, i, k-1), sum(a, i, n-1)));
    }
    return minv;
}
int main() {
    int a[] = {100, 200, 300, 400, 500, 600, 700, 800, 900 };
    cout<<partition(a, 9, 3);
    getchar();
    return 0;
}