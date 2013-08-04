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
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int len1 = matrix.size();
		if(!len1)
			return false;
		int len2 = matrix[0].size();
		int i;
		for(i = 0; i < len1; i++)
		{
			if(matrix[i][len2-1] >= target)
				break;
		}
		if(i == len1)
			return false;
		int j;
		for(j = len2-1; j >= 0; j--)
		{
			if(matrix[i][j] == target)
				return true;
		}
		return false;
	}
};