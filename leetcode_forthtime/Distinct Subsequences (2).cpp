class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lens = S.size();
        int lent = T.size();
        vector<vector<int>> dp(lent+1, vector<int>(lens+1));
        for(int i = 0; i <= lens; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= lent; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= lent; i++)
        {
            for(int j = 1; j <= lens; j++)
            {
                if(T[i-1] == S[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[lent][lens];
    }
};