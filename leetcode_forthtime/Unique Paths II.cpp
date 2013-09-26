class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &a) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = a.size();
        if(m <= 0)
            return 0;
        int n = a[0].size();
       if(n <= 0)
            return 0;
        vector<int> dp(n);
        dp[0] = (a[0][0] == 0) ? 1:0;
        for(int i = 1; i < n; i++)
        {
            dp[i] = (a[0][i] == 0)?dp[i-1]:0;
        }
        for(int i = 1; i < m; i++)
        {
            dp[0] = (a[i][0] == 0) ? dp[0]:0;
            for(int j = 1; j < n; j++)
                dp[j] = (a[i][j] == 0) ? (dp[j] + dp[j-1]):0;
        }
        return dp[n-1];
    }
};