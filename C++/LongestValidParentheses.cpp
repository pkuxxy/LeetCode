#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Node
{
public:
	char ch;
	int index;
	Node(char c, int i)
	{
		ch = c;
		index = i;
	}

};
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len = s.size();
		if(!len)
			return 0;
		stack<Node> nodes;
		nodes.push(Node(')',-1));
		int ret = 0;
		for(int i = 0; i < len; i++)
		{
			if(s[i] == '(')
				nodes.push(Node('(',i));
			else
			{
				Node top = nodes.top();
				if(top.ch == '(')
				{
					nodes.pop();
					ret = max(ret, i - nodes.top().index);
				}
				else
					nodes.push(Node(')',i));
			}
		}
		return ret;
        return 0;
    }
};