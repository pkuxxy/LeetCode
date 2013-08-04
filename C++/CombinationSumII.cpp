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
	void dfs(int index, vector<int>& num, int target, vector<int>& path)
	{
		if(target < 0)
			return;
		if(target == 0)
		{
			ret.push_back(vector<int>(path));
			return;
		}
		for(int i = index; i < num.size(); i++)
		{
			if(i != index && num[i] == num[i-1])
				continue;
			path.push_back(num[i]);
			dfs(i+1, num, target - num[i], path);
			path.pop_back();
		}
	}
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ret.clear();
		vector<int> path;
		sort(num.begin(), num.end());
		dfs(0, num, target, path);
		return ret;
    }
};