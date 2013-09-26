class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lens = S.size();
        int lent = T.size();
        if(!lens || !lent)
            return 0;
        vector<vector<int>> dp(lent, vector<int>(lens, 0));
        dp[0][0] = (S[0] == T[0]);
        for(int i = 1; i < lens; i++)
        {
            dp[0][i] = (S[i] == T[0]? (dp[0][i-1]+1):dp[0][i-1]);
        }
        for(int i = 1; i < lent; i++)
        {
            for(int j = i; j < lens; j++)
            {
                if(S[j] == T[i])
                    dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[lent-1][lens-1];
    }
};