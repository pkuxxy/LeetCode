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
    bool isMatch(const char *s, const char *p) {
        if(!s || !p)
			return false;
		int len1 = strlen(s);
		int len2 = strlen(p);
		int i = 0;
		int j = 0;
		int indexi = 0;
		int indexj = 0;
		bool star = false;
		while(i < len1)
		{
			if(j == len2)
			{
				if(star)
					indexi++;
				else
					return false;
				i = indexi;
				j = indexj;
			}
			else if(p[j] == '*')
			{
				star = true;
				while(j < len2 && p[j] == '*')
					j++;
				if(j == len2)
					return true;
				indexi = i;
				indexj = j;
			}
			else if(s[i] == p[j] || p[j] == '?')
			{
				i++;
				j++;
			}
			else
			{
				if(star)
					indexi++;
				else
					return false;
				i = indexi;
				j = indexj;
			}
		}
		while(j < len2 && p[j] == '*')
			j++;
		return j == len2;
    }
};