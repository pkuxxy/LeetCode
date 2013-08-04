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
    bool isScramble(string s1, string s2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s1 == s2)
			return true;
		int len1 = s1.size();
		int len2 = s2.size();
		if(len1 != len2)
			return false;
		for(int i = 1; i <= len1/2; i++)
		{
			string a1 = s1.substr(0,i);
			string b1 = s1.substr(i);
			string a2 = s2.substr(0,i);
			string b2 = s2.substr(i);
			string c1 = s1.substr(0,len1-i);
			string d1 = s1.substr(len1-i);
			string c2 = s2.substr(0,len1-i);
			string d2 = s2.substr(len1-i);
			if(isScramble(a1, a2) && isScramble(b1, b2))
				return true;
			if(isScramble(a1, d2) && isScramble(b1, c2))
				return true;
			if(isScramble(d1, d2) && isScramble(c1, c2))
				return true;
			if( isScramble(d1, a2) && isScramble(c1, b2))
				return true;
		}
		return false;
	}
};
