#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
	bool isAlpha(char ch)
	{
		return ((ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'));
	}
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int i = 0;
		int j = s.size()-1;
		while(i < j)
		{
			while(i < j && !isAlpha(s[i]))
				i++;
			if(i >= j)
				break;
			while(i < j && !isAlpha(s[j]))
				j--;
			if(i >= j)
				break;
			if(s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	
};
