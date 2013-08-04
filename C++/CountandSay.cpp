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
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1)
			return "";
		string ret = "1";
		while(--n)
		{
			int count = 1;
			string next;
			int i = 0;
			for(i = 0; i < ret.size()-1; i++)
			{
				if(ret[i] == ret[i+1])
				{
					count++;
					continue;
				}
				else
				{
					next.push_back(count+'0');
					next.push_back(ret[i]);
					count = 1;
				}
			}
			next.push_back(count+'0');
			next.push_back(ret[i]);
			ret = next;
		}
		return ret;
    }
};