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
	int largestRectangleArea(vector<int>& height)
	{
		int len = height.size();
		vector<int> left(len, 0);
		vector<int> right(len, len);
		for(int i = 0; i < len; i++)
		{
			left[i] = i;
			while(left[i] >= 1 && height[i] <= height[left[i]-1])
			{
				left[i] = left[left[i]-1];
			}
		}
		for(int i = len-1; i >= 0; i--)
		{
			right[i] = i;
			while(right[i] < len-1 && height[i] <= height[right[i]+1])
			{
				right[i] = right[right[i]+1];
			}
		}
		int maxSum = 0;
		for(int i = 0; i < len; i++)
		{
			maxSum = max(maxSum, height[i] * (right[i] - left[i]+1));
		}
		return maxSum;
	}
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1 = matrix.size();
		if(!len1)
			return 0;
		int len2 = matrix[0].size();
		vector<int> height(len2, 0);
		int maxSum = 0;
		for(int i = 0; i < len1; i++)
		{
			for(int j = 0; j < len2; j++)
			{
				if(matrix[i][j] == '1')
					height[j] += 1;
				else
					height[j] = 0;
			}
			maxSum = max(maxSum, largestRectangleArea(height));
		}
		return maxSum;
    }
};