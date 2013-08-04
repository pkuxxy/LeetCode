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
	void dfs(int index, int size, vector<int>& s, vector<int> path)
	{
		if(index == size)
		{
			ret.push_back(path);
			return;
		}
		dfs(index+1, size, s, path);
		path.push_back(s[index]);
		dfs(index+1, size, s, path);
		path.pop_back();
	}
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ret.clear();
		sort(S.begin(), S.end());
		vector<int> path;
		dfs(0, S.size(), S, path);
		return ret;
    }
};