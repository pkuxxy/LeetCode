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
	bool match(const char *s, int sindex, int sizes, const char *p, int pindex, int sizep)
	{
		if(sindex > sizes)
			return false;
		if(sindex == sizes && pindex == sizep)
			return true;
		
		if(pindex < sizep-1 && p[pindex+1] == '*')
		{
			if(p[pindex] == '.')
			{
				for(int i = sindex; i <= sizes; i++)
				{
					if(match(s, i, sizes, p, pindex+2, sizep))
						return true;
				}
				return false;
			}
			else
			{
				int i = sindex;
				for(; i <= sizes; i++)
				{
					if(s[i] != p[pindex])
						break;
					if(match(s, i, sizes, p, pindex+2, sizep))
						return true;
				}
				return match(s, i ,sizes, p, pindex+2, sizep);
			}
		}
		else if(p[pindex] == '.')
			return match(s, sindex+1, sizes, p, pindex+1, sizep);
		else
		{
			if(s[sindex] == p[pindex])
				return match(s, sindex+1, sizes, p, pindex+1, sizep);
			else
				return false;
		}
	}
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(!s && !p)
			return true;
		else if(!s || !p)
			return false;
		int lens = strlen(s);
		int lenp = strlen(p);
		return match(s, 0, lens, p,0, lenp);
	}
};
int main()
{
	char s[] = "";
	char p[] = ".ac*";
	Solution sol;
	cout<<sol.isMatch(s,p);
	getchar();
}