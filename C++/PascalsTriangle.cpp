#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int>> ret;
		if(numRows <= 0)
			return ret;
		vector<int> list;
		list.push_back(1);
		ret.push_back(vector<int>(list));
		for(int i = 1; i < numRows; i++)
		{
			list.clear();
			vector<int> pre = ret[i-1];
			list.push_back(1);
			for(int j = 1; j < i; j++)
				list.push_back(pre[j-1] + pre[j]);
			list.push_back(1);
			ret.push_back(vector<int>(list));
		}
		return ret;
    }
};