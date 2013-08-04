#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ret;
		if(rowIndex < 0)
			return ret;
		vector<int> pre;
		pre.push_back(1);
		ret.push_back(1);
		for(int i = 1; i <= rowIndex; i++)
		{
			ret.clear();
			ret.push_back(1);
			for(int j = 1; j < i; j++)
			{
				ret.push_back(pre[j-1] + pre[j]);
			}
			ret.push_back(1);
			pre = vector<int>(ret);
		}
		return ret;
    }
};