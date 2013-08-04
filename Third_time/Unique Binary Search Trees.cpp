class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 0;
        vector<int> dp(n+1,1);
        for(int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for(int j = 0; j < i; j++)
            {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};