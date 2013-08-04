#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(height.size() <= 1)
			return 0;
		int max = 0;
		int i = 0;
		int j = height.size()-1;
		while(i < j)
		{
			int minH = min(height[i], height[j]);
			int cap = minH * (j - i);
			if(cap > max)
				max = cap;
			if(height[i] < height[j])
			{
				i++;
				while(i < j && height[i] <= minH)
					i++;
			}
			else
			{
				j--;
				while(i < j && height[j] <= minH)
					j--;
			}
		}
		return max;
    }
};