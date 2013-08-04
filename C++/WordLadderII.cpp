#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<unordered_set>
#include<string.h>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	void clear(stack<string>& s)
	{
		while(!s.empty())
		{
			s.pop();
		}
	}
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		unordered_set<string> added;
		queue<string> q;
		vector<vector<string>> ret;
		map<string, string> backtrack;
		stack<string> tmp;
		bool first = true;
		int min = 0;
		q.push(start);
		added.insert(start);
		while(!q.empty())
		{
			string s = q.front(); q.pop();

			for(int i = 0; i < s.length(); i++) 
			{
				string t = s;
				for(char c = 'a'; c < 'z'; c++)
				{	
					t[i] = c;
					if(t == end)
					{
						clear(tmp);
						tmp.push(end);
						tmp.push(s);
						map<string, string>::iterator iter = backtrack.find(s);
						while(iter != backtrack.end())
						{
							tmp.push(iter->second);
							iter = backtrack.find(iter->second);
						}
						vector<string> vec;
						while(!tmp.empty())
						{
							vec.push_back(tmp.top());
							tmp.pop();
						}
						if(first)
						{
							first = false;
							min = vec.size();
						}
						else
						{
							if(vec.size() > min)
								return ret;
						}
						ret.push_back(vec);	
					}
					if(dict.find(t) != dict.end() && added.find(t) == added.end()) 
					{
						q.push(t);
						added.insert(t);
						backtrack.insert(map<string, string>::value_type(t, s));
					}
				}
			}
		}

		return ret;
	}
};
int main()
{
	string begin = "red";
	string end = "tax";
	unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");
	Solution sol;
	vector<vector<string>> ret = sol.findLadders(begin, end, dict);
	for(int i = 0; i < ret.size(); i++)
	{
		vector<string> cur = ret[i];
		for(int j = 0; j < cur.size(); j++)
		{
			cout << cur[j] << " ";
		}
		cout<<endl;
	}
	getchar();
}