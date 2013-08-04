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
	bool solve(string& s1, int index1, int len1, string& s2, int index2, int len2, string& s3, int index3, int len3)
	{
		if(index1 == len1 && index2 == len2)
		{
			return index3 == len3;
		}
		else if(index1 == len1)
		{
			return s2.substr(index2) == s3.substr(index3);
		}
		else if(index2 == len2)
			return s1.substr(index1) == s3.substr(index3);
		if(s1[index1] != s3[index3] && s2[index2] != s3[index3])
			return false;
		else 
		{
			if(s1[index1] == s3[index3] && solve(s1, index1+1, len1, s2, index2, len2, s3, index3+1, len3))
				return true;
			else
				return solve(s1, index1, len1, s2, index2+1, len2, s3, index3+1, len3);
		}
	}
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if(len1 + len2 != len3)
			return false;
		return solve(s1, 0, len1, s2, 0, len2, s3, 0, len3);
    }
};