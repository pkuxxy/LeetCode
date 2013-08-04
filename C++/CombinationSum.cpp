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
	vector<int> count;
	void dfs(int index, vector<int> &candidates, int target)
	{
		if(target < 0)
			return;
		if(index == candidates.size())
		{
			if(target != 0)
				return;
			vector<int> list;
			for(int i = 0; i < candidates.size(); i++)
			{
				for(int j = 0; j < count[i]; j++)
				{
					list.push_back(candidates[i]);
				}
			}
			ret.push_back(list);
			return;
		}
		for(int i = 0; i <= target/candidates[index];i++)
		{
			count[index] = i;
			dfs(index+1, candidates, target - i * candidates[index]);
		}
	}
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ret.clear();
		count = vector<int>(candidates.size());
		sort(candidates.begin(), candidates.end());
		dfs(0, candidates, target);
		return ret;
    }
};