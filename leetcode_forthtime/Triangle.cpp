class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = triangle.size();
        if(!len1)
            return 0;
        vector<int> dp(len1,0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < len1; i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(j == i)
                    dp[j] = dp[j-1]+triangle[i][j];
                else if(j == 0)
                    dp[j] += triangle[i][j];
                else
                    dp[j] = dp[j-1] > dp[j] ? dp[j]+triangle[i][j] : dp[j-1] + triangle[i][j];
            }
        }
        int minv = INT_MAX;
        for(int i = 0; i < len1; i++)
            minv = min(minv, dp[i]);
        return minv;
    }
};