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
	string addBinary(string a, string b) {
		int len = max(a.size(), b.size()) + 1;
		char* sum = new char[len];
		memset(sum, 0, len);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int i = 0;
		for(i = 0; i < min(a.size(),b.size()); i++)
		{
			sum[i] += a[i] - '0' + b[i] - '0';
			if(sum[i] >= 2)
			{
				sum[i] %= 2;
				sum[i+1] += 1;
			}
		}
		while(i < a.size())
		{
			sum[i] += a[i] - '0';
			if(sum[i] >= 2)
			{
				sum[i] %= 2;
				sum[i+1] += 1;
			}
			i++;
		}
		while(i < b.size())
		{
			sum[i] += b[i] - '0';
			if(sum[i] >= 2)
			{
				sum[i] %= 2;
				sum[i+1] += 1;
			}
			i++;
		}
		if(sum[i] >= 2)
		{
			sum[i] %= 2;
			sum[i+1] += 1;
			i++;
		}
		while(sum[i] == 0)
			i--;
		if(i < 0)
			return "0";
		string ret;
		while(i >= 0)
		{
			ret.push_back(sum[i--]+'0');
		}
		delete[] sum;
		return ret;
	}
};
int main()
{
	string a = "0";
	string b = "1";
	Solution sol;
	cout<<sol.addBinary(a, b)<<endl;
	getchar();
}