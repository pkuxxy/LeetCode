#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> ret;
	void dfs(int index, int lc, int rc, int n, string list)
	{
		if(index == n)
		{
			ret.push_back(list);
			return;
		}
		if(lc > 0)
		{
			list.push_back('(');
			dfs(index + 1, lc - 1, rc, n, list);
			list.pop_back();
		}
		if(rc > lc)
		{
			list.push_back(')');
			dfs(index + 1, lc, rc-1, n, list);
			list.pop_back();
		}
	}
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ret.clear();
		string list;
		dfs(0, n, n, 2*n, list);
		return ret;
    }
};