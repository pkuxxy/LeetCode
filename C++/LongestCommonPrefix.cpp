#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string ret;
		if(strs.size() == 0)
			return ret;
		string first = strs[0];
		bool conti = true;
		for(int i = 0; i < first.size(); i++)
		{
			for(int j = 1; j < strs.size(); j++)
			{
				if(strs[j][i] != first[i])
				{
					conti = false;
					break;
				}
			}
			if(!conti)
				break;
			else
				ret.push_back(first[i]);
		}
		return ret;
	}
};