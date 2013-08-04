class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = S.size();
        int len2 = T.size();
        if(!len1 || !len2)
            return 0;
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        for(int i = 1; i <= len1; i++)
        {
            if(S[i-1] == T[0])
                dp[i][1] = dp[i-1][1]+1;
            else
                dp[i][1] = dp[i-1][1];
        }
        for(int i = 2; i <= len1; i++)
        {
            for(int j = 2; j <= len2; j++)
            {
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[len1][len2];
    }
};