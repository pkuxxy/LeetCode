// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int getMaxA(int n)
{
    if(n <= 3)
        return n;
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1]+1;
        for(int k = 4; k < i; k++)
        {
            dp[i] = max(dp[i], (k-2)*dp[i-k]);
        }
    }
    return dp[n];
}
int main() {
    cout<<getMaxA(27)<<endl;
    return 0;
}