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
	vector<vector<int>> ret;
	vector<bool> used;
	void dfs(int index, vector<int>& num, vector<int>& path)
	{
		if(index == num.size())
		{
			ret.push_back(vector<int>(path));
			return;
		}
		for(int i = 0; i < num.size(); i++)
		{
			if(used[i])
				continue;
			path.push_back(num[i]);
			used[i] = true;
			dfs(index+1, num, path);
			used[i] = false;
			path.pop_back();
		}
	}
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ret.clear();
		used.resize(num.size());
		for(int i = 0; i < used.size(); i++)
		{
			used[i] = false;
		}
		vector<int> path;
		dfs(0, num, path);
		return ret;

    }
};