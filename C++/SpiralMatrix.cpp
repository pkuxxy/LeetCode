#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ret;
		int len1 = matrix.size();
		if(!len1)
			return ret;
		int len2 = matrix[0].size();
		int small = min(len1, len2);
		int big = max(len1, len2);
		int level = 0;
		for(; level < small/2; level++)
		{
			for(int i = level; i < len2-level; i++)
				ret.push_back(matrix[level][i]);
			for(int i = level+1; i < len1 - level; i++)
				ret.push_back(matrix[i][len2 - level - 1]);
			for(int i = len2 - level - 2; i >= level; i--)
				ret.push_back(matrix[len1 - level - 1][i]);
			for(int i = len1 - level - 2; i >= level+1; i--)
				ret.push_back(matrix[i][level]);
		}
		if(small % 2)
		{
			if(big == len1)
			{
				for(int i = level; i < len1 - level; i++)
					ret.push_back(matrix[i][level]);
			}
			else
			{
				for(int i = level; i < len2 - level; i++)
					ret.push_back(matrix[level][i]);
			}
		}
		return ret;
    }
};
int main()
{
	int tmp[3][2] = {{2,5},{8,4},{0,-1}};
	vector<vector<int>> matrix(3);
	for(int i = 0; i < 3; i++)
	{
		matrix[i] = vector<int>(tmp[i], tmp[i] + 2);
	}
	Solution sol;
	sol.spiralOrder(matrix);
	getchar();
}