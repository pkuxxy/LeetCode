#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		map<char, int> imap ;
		int max = 0;
		int sum = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(imap.find(s[i]) == imap.end())
			{
				sum++;
				imap[s[i]] = i;
			}
			else
			{
				if(max < sum)
					max = sum;
				int start = imap.find(s[i])->second + 1;
				sum = i - start + 1;
				imap.clear();
				for(int j = start; j <=i; j++)
					imap[s[j]] = j;
			}
		}
		if(max < sum)
			max = sum;
		return max;
    }
};