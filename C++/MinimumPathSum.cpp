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
	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len1 = grid.size();
		if(len1 == 0)
			return 0;
		int len2 = grid[0].size();
		vector<vector<int>> sum(len1);
		for(int i = 0; i < sum.size(); i++)
		{
			sum[i] = vector<int>(len2);
		}
		sum[0][0] = grid[0][0];
		for(int i = 1; i < len1; i++)
		{
			sum[i][0] = sum[i-1][0] + grid[i][0];
		}
		for(int i = 1; i < len2; i++)
		{
			sum[0][i] = sum[0][i-1] + grid[0][i];
		}
		for(int i = 1; i < len1; i ++)
		{
			for(int j = 1; j < len2; j++)
			{

				sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
			}
		}
		return sum[len1-1][len2-1];
	}
};