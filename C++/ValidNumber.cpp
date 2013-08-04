#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;
class Solution {
public:
	bool isNum(char ch)
	{
		return (ch >= '0' && ch <= '9');
	}
	string trim(string& s)
	{
		if (s.empty()) return s;
		s.erase(0,s.find_first_not_of("\n"));
		s.erase(s.find_last_not_of("\n") + 1);

		s.erase(0,s.find_first_not_of("\r"));
		s.erase(s.find_last_not_of("\r") + 1);

		s.erase(0,s.find_first_not_of("\t"));
		s.erase(s.find_last_not_of("\t") + 1);

		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		return s;
	}
	bool isNumber(const char *s) {
		if(!s)
			return false;
		bool hasNumber = false;
		bool hasE = false;
		bool hasDot = false;
		string str(s);
		trim(str);
		for(int i = 0; i < str.size(); i++)
		{
			if(!isNum(str[i]) && str[i] != 'e' && str[i] != '.' && str[i] != '+' && str[i] != '-')
				return false;
			if(str[i] == '+' || str[i] == '-')
			{
				if((i != 0 && str[i-1] != 'e') || i == str.size()-1)
					return false;
			}
			else if(str[i] == 'e')
			{
				if(!hasNumber || hasE || i == str.size()-1)
					return false;
				else
					hasE = true;
			}
			else if(str[i] == '.')
			{
				if(hasDot || hasE)
					return false;
				else
					hasDot = true;
			}
			else
				hasNumber = true;
		}
		if(!hasNumber)
			return false;
		return true;
	}
};
int main()
{
	char* s = "0";
	Solution sol;
	cout<<sol.isNumber(s);
	getchar();
}