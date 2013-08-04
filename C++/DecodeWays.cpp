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
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s.size();
		if(len == 0)
			return 0;
		vector<int> ways(len+1);

		ways[0] = 1;
		int pre = s[0]-'0';
		if(pre == 0)
			ways[1] = 0;
		else
			ways[1] = 1;
		for(int i = 1; i < len; i++)
		{
			int cur = s[i] - '0';
			if(cur > 6)
			{
				if(pre >= 2 || pre == 0)
					ways[i+1] = ways[i];
				else
					ways[i+1] = ways[i] + ways[i-1];
			}
			else if(cur >= 1)
			{
				if(pre >= 3 || pre == 0)
					ways[i+1] = ways[i];
				else
					ways[i+1] = ways[i] + ways[i-1];
			}
			else
			{
				if(pre >= 3 || pre == 0)
					return 0;
				else
					ways[i+1] = ways[i-1];
			}
			pre = cur;
		}
		return ways[len];
	}
};