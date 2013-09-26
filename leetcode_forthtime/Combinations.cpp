#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int index, int len, int k, vector<int>& path)
    {
        if(k == 0)
        {
            ret.push_back(path);
            return;
        }
        for(int i = index; i <= len; i++)
        {
            path.push_back(i);
            dfs(i+1, len, k-1, path);
            path.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(n < 1 || k > n)
            return ret;
        vector<int> path;
        dfs(1, n, k, path);
        return ret;
    }
};
int main()
{
	string s = "ABC";
	int nRows = 2;
	vector<vector<int>> grid(2, vector<int>(2,1));
	grid[0][1] = 2;
	Solution sol;
	sol.combine(2,2);
	getchar();
}