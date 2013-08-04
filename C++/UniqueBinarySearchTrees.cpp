#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				dp[i] += dp[j-1]*dp[i-j];
			}
		}
		return dp[n];
    }
};