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
	vector<vector<int> > ret;
	void dfs(int start, int nums, int n, int k, vector<int>& path)
	{
		if(nums == k)
		{
			ret.push_back(vector<int>(path));
			return;
		}
		if(start > n)
			return;
		for(int i = start; i <= n; i++)
		{
			path.push_back(i);
			dfs(i+1, nums + 1, n, k, path);
			path.pop_back();
		}
	}
	vector<vector<int> > combine(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		if(n == 0 || k == 0)
			return ret;
		vector<int> path;
		dfs(1, 0, n, k, path);
		return ret;
	}
};