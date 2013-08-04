#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;
map<char, string> vm;
void init()
{
	vm['2'] = "abc";
	vm['3'] = "def";
	vm['4'] = "ghi";
	vm['5'] = "jkl";
	vm['6'] = "mno";
	vm['7'] = "pqrs";
	vm['8'] = "tuv";
	vm['9'] = "wxyz";
}
class Solution {
public:
	vector<string> ret;
	void dfs(string digits, int index, int size, string& list)
	{
		if(index == size)
		{
			ret.push_back(list);
			return;
		}
		string alpha = vm.find(digits[index])->second;
		for(int i = 0; i < alpha.size(); i++)
		{
			list.push_back(alpha[i]);
			dfs(digits, index+1, size, list);
			list.pop_back();
		}
	}
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		init();
		ret.clear();
		string list;
		dfs(digits, 0, digits.size(), list);
        return ret;
    }
};
int main()
{
	string d = "2";
	Solution sol;
	sol.letterCombinations(d);
	getchar();
}