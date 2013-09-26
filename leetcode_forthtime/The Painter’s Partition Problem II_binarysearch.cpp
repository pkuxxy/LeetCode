// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include<math.h>
#include<vector>
using namespace std;
int getRequiredPar(int a[], int n, int sum)
{
    int total = 0;
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        total += a[i];
        if(total > sum)
        {
            total = a[i];
            count++;
        }
    }
    return count;
}
int partition(int a[], int n, int k)
{
    vector<int> sum(n+1,0);
    vector<vector<int>> m(n+1, vector<int>(k+1, 0));
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i-1];
    }
    int l = 0;
    int r = n;
    int mid = l+(r-l)/2;
    while(l <= n)
    {
        mid = l + (r-l)/2;
        int p1 = getRequiredPar(a, n, sum[mid]);
        int p2 = getRequiredPar(a, n, sum[mid+1]);
        if(p1 == k+1 && p2 == k)
            break;
        else if(p1 > k+1)
            l = mid+1;
        else
            r = mid-1;
    }
    l = sum[mid];
    r = sum[mid+1];
    while(l < r)
    {
        mid = l + (r-l)/2;
        int p = getRequiredPar(a, n, mid);
        if(p <= k)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}
int main() {
    int a[] = {100, 200, 300, 400, 500, 600, 700, 800, 900 };
    cout<<partition(a, 9, 3);
    
    return 0;
}