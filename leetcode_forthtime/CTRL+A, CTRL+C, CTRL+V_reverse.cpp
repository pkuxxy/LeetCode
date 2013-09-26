// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int getMinPress(int n)
{
    if(n <= 3)
        return n;
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1]+1;
        for(int k = 2; k < i; k++)
        {
            if(i%k == 0)
                dp[i] = min(dp[i], dp[i/k]+k+2);
        }
    }
    return dp[n];
}
int main() {
    cout<<getMinPress(100)<<endl;
    return 0;
}