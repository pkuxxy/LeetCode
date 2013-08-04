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
    string simplifyPath(string path) {
        vector<string> s;
		int start = 0;
		int len = 0;
		for(int i = 0; i < path.size(); i++)
		{
			if(path[i] == '/')
			{
				if(len == 0)
				{
					start = i+1;
					continue;
				}
				string cur = path.substr(start, len);
				if(cur == "..")
				{
					if(!s.empty())
						s.pop_back();
				}
				else if(cur != ".")
					s.push_back(cur);
				start = i+1;
				len = 0;
			}
			else
				len++;
		}
		if(len != 0)
		{
			string cur = path.substr(start,len);
			if(cur == "..")
			{
				if(!s.empty())
					s.pop_back();
			}
			else if(cur != ".")
				s.push_back(cur);
		}
		string ret;
		ret.push_back('/');
		if(s.empty())
			return ret;
		for(int i = 0; i < s.size()-1; i++)
		{
			ret.append(s[i]).push_back('/');
		}
		ret.append(s[s.size()-1]);
		return ret;
    }
};
int main()
{
	string path = "///eHx/..";
	Solution sol;
	cout<<sol.simplifyPath(path)<<endl;
	getchar();
}