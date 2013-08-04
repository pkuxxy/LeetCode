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
	bool match(const char* s, int si, int ss, const char* p, int pi, int ps)
	{
		if(si == ss && pi == ps)
			return true;
		else if(pi == ps)
			return false;
		if(p[pi] == '?')
			return match(s, si+1, ss, p, pi+1, ps);
		else if(p[pi] == '*')
		{
			for(int i = si; i <= ss; i++)
			{
				if(match(s, i, ss, p, pi+1, ps))
					return true;
			}
			return false;
		}
		else if(s[si] == p[pi])
			return match(s, si+1, ss, p, pi+1, ps);
		else
			return false;
	}
	string simp(const char* s)
	{
		string ret;
		int len = strlen(s);
		if(!len)
			return ret;
		ret.push_back(s[0]);
		for(int i = 1; i < len; i++)
		{
			if(s[i] == s[i-1] && s[i] == '*')
				continue;
			ret.push_back(s[i]);
		}
		return ret;
	}
    bool isMatch(const char *s, const char *p) {
        if(!s || !p)
			return false;
		string ps = simp(p);
		int lens = strlen(s);
		int lenp = ps.size();
		return match(s, 0, lens, ps.c_str(), 0, lenp);
    }
};
int main()
{
	char s[] = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"; 
	char p[] = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
	Solution sol;
	cout<<sol.isMatch(s,p);
	getchar();
}