#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
const int intmax = 2147483647;
const int intmin = -2147483648;
class Solution {
public:

	bool isNum(char ch)
	{
		if(ch >= '0' && ch <= '9')
			return true;
		return false;
	}
	int atoi(const char *str) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!str)
			return 0;
		int len = strlen(str);
		if(len == 0)
			return 0;
		int i = 0;
		while(str[i] == ' ')
			i++;
		if(!str[i])
			return 0;
		bool sign = true;
		if(str[i] == '-' || str[i] == '+')
		{
			sign = str[i] == '+' ? true : false;
			i++;
		}
		else if(!isNum(str[i]))
			return 0;
		int sum = 0;
		int count = 0;
		while(isNum(str[i]))
		{
			sum *= 10;
			sum += str[i] - '0';
			i++;
			count++;
			if(count > 10 || sum < 0)
				return sign ? intmax : intmin;
		}
		return sign ? sum:-sum;
	}
};
int main()
{
	Solution sol;
	cout<<sol.atoi("10557266014");
	getchar();
}