#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 != len2)
            return false;
        vector<vector<vector<bool>>> dp(len1, vector<vector<bool>>(len1, vector<bool>(len1+1, false)));
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len1; j++)
            {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        for(int l = 2; l <= len1; l++)
        {
            for(int i = 0; i <= len1-l; i++)
            {
                for(int j = 0; j <= len1-l; j++)
                {
                    for(int k = 1; k < l; k++)
                    {
                        if((dp[i][j][k] && dp[i+k][j+k][l-k])
                            || (dp[i][j+l-k][k] && dp[i+k][j][l-k]))
                        {
                            dp[i][j][l] = true;
                            //i = j = len1;
    						break;
                        }
                    }
                }
            }
        }
        return dp[0][0][len1];
    }
};
