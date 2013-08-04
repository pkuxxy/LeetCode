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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1 = obstacleGrid.size();
		if(len1 == 0)
			return 0;
		int len2 = obstacleGrid[0].size();
		vector<vector<int>> sum(len1);
		for(int i = 0; i < sum.size(); i++)
		{
			sum[i] = vector<int>(len2);
		}
		for(int i = 0; i < len1; i ++)
		{
			for(int j = 0; j < len2; j++)
			{
				if(obstacleGrid[i][j] == 1)
					sum[i][j] = 0;
				else if(i == 0 && j == 0)
					sum[i][j] = 1;
				else if(i == 0)
					sum[i][j] = sum[i][j-1];
				else if(j == 0)
					sum[i][j] = sum[i-1][j];
				else
					sum[i][j] = sum[i-1][j] + sum[i][j-1];
			}
		}
		return sum[len1-1][len2-1];
    }
};