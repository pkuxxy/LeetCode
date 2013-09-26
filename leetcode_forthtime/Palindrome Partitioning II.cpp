class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return 0;
        vector<vector<bool>> dp1(len, vector<bool>(len, false));
        for(int l = 1; l <= len; l++)
        {
            for(int i = 0; i <= len-l; i++)
            {
                if(l == 1)
                    dp1[i][i] = true;
                else if(l == 2)
                    dp1[i][i+1] = (s[i] == s[i+1]);
                else
                    dp1[i][i+l-1] = (s[i] == s[i+l-1] && dp1[i+1][i+l-2]);
            }
        }
        vector<int> dp2(len, 0);
        for(int i = 1; i < len; i++)
        {
            dp2[i] = dp2[i-1]+1;
            for(int j = i-1; j >= 0; j--)
            {
                if(dp1[j][i])
                    dp2[i] = (j == 0)?0:min(dp2[i],dp2[j-1]+1);
            }
        }
        return dp2[len-1];
    }
};