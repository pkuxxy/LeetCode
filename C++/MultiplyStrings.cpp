#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1 = num1.size();
		int len2 = num2.size();
		if(!len1 || !len2)
			return num1+num2;
		vector<int> sum(len1+len2,0);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for(int i = 0; i < len1; i++)
		{
			for(int j = 0; j < len2; j++)
			{
				sum[i+j] += (num1[i]-'0') * (num2[j]-'0');
			}
		}
		string ret;
		for(int i = 0; i < len1 + len2-1; i++)
		{
			if(sum[i] > 9)
			{
				sum[i+1] += sum[i]/10;
				sum[i] %= 10;
			}
		}
		int i;
		for(i = len1+len2-1; i >= 0; i--)
		{
			if(sum[i] != 0)
				break;
		}
		if(i < 0)
			return "0";
		for(; i >= 0; i--)
		{
			ret.push_back('0'+sum[i]);
		}
		return ret;
    }
};
int main()
{
	string a = "123";
	string b = "456";
	Solution sol;
	cout<<sol.multiply(a,b);
	getchar();
}