#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
	int grid[101][101];
    int uniquePaths(int m, int n) {
		for(int i = 0; i < m; i++)
			grid[i][0] = 1;
		for(int i = 0; i < n; i++)
			grid[0][i] = 1;
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				grid[i][j] = grid[i-1][j] + grid[i][j-1];
			}
		}
		return grid[m-1][n-1];
    }
};