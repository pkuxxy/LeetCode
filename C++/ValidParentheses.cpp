#include<iostream>
#include<stdlib.h>
#include<stack>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Pair
{
public:
	int type;
	int pos;
	Pair(){}
	Pair(int t, int p)
	{
		type = t;
		pos = p;
	}
};
map<char, Pair> vm;
void init()
{
	vm['('] = Pair(0, 0);
	vm[')'] = Pair(0, 1);
	vm['['] = Pair(1, 0);
	vm[']'] = Pair(1, 1);
	vm['{'] = Pair(2, 0);
	vm['}'] = Pair(2, 1);
}
class Solution {
public:
	bool isValid(string s) {
		init();
		stack<char> st;
		for(int i = 0; i < s.size(); i++)
		{
			Pair cur = vm[s[i]];
			if(cur.pos == 0)
				st.push(s[i]);
			else
			{
				if(st.empty())
					return false;
				Pair top = vm[st.top()];
				if(top.type != cur.type)
					return false;
				st.pop();
			}
		}
		if(st.empty())
			return true;
		else
			return false;
	}
};
int main()
{
	string s = "]";
	Solution sol;
	cout<<sol.isValid(s);
	getchar();
}