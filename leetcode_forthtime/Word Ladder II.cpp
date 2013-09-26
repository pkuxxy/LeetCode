#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include<vector>
#include<unordered_set>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
	vector<vector<string>> ret;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		int len = start.size();
		if(!len || len != end.size())
			return ret;
		map<string, string> m;
		queue<string> q;
		q.push(start);
		m[start] = "";
		while(!q.empty())
		{
			string cur = q.front();
			q.pop();
			for(int i = 0; i < len; i++)
			{
				string tmp = cur;
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					if(cur[i] == ch)
						continue;
					tmp[i] = ch;
					if(tmp == end)
					{
						vector<string> list;
						list.push_back(end);
						list.push_back(cur);
						map<string, string>::iterator iter = m.find(cur);
						while(iter->second != "")
						{
							list.push_back(iter->second);
							iter = m.find(iter->second);
						}
						reverse(list.begin(), list.end());
						ret.push_back(list);
					}
					else if(dict.find(tmp) != dict.end() && m.find(tmp) == m.end())
					{
						q.push(tmp);
						m[tmp] = cur;
					}
				}
			}
		}
		return ret;
	}
};

int main() {
	string start = "a";
	string end = "c";
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	Solution sol;
	sol.findLadders(start, end, dict);
	getchar();
	return 0;
}