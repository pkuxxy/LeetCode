class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m <= 0 || n <= 0)
            return 0;
        vector<int> dp(n, 1);
        while(m-- > 1)
        {
            for(int i = 1; i < n; i++)
                dp[i] += dp[i-1];
        }
        return dp[n-1];
    }
};