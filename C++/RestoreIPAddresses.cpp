#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> ret;
	void dfs(int index, int size, string s, vector<string>& path)
	{
		if(index >= size)
		{
			if(path.size() == 4)
			{
				string str;
				for(int i = 0; i < 3; i++)
				{
					str.append(path[i]).push_back('.');
				}
				str.append(path[3]);
				ret.push_back(str);
			}
			return;
		}
		char tmp[4];
		stringstream sst;
		for(int len = 1; len <= 3 && index + len <= size; len++)
		{
			string cur = s.substr(index, len);
			if(len > 1 && cur[0] == '0')
				continue;
			int d = atoi(cur.c_str());
			if(d >= 0 && d <= 255)
			{
				//path.push_back(itoa(d,tmp,10));
				sst.str("");
				sst<<d;
				//cout<<d<<" "<<sst.str()<<"."<<endl;
				path.push_back(sst.str());
				dfs(index+len, size,s, path);
				path.pop_back();
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ret.clear();
		vector<string> path;
		dfs(0, s.size(), s, path);
		return ret;
    }
};
int main()
{
	string s = "010010";
	Solution sol;
	sol.restoreIpAddresses(s);
	getchar();
}