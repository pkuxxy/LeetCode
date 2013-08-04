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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n);
		for(int i = 0; i < n; i++)
		{
			ret[i] = vector<int>(n);
		}
		int level = 0;
		int count = 1;
		for(level = 0; level < n/2; level++)
		{
			for(int i = level; i < n - level; i++)
			{
				ret[level][i] = count++;
			}
			for(int i = level+1; i < n - level; i++)
			{
				ret[i][n-level-1] = count++;
			}
			for(int i = n - level- 2; i >= level; i--)
			{
				ret[n - level-1][i] = count++;
			}
			for(int i = n - level - 2; i >= level+1; i--)
			{
				ret[i][level] = count++;
			}
		}
		if(n%2 == 1)
			ret[n/2][n/2] = count;
		return ret;
    }
};