#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> all;
	bool isPalin(string s, int start, int end)
	{
		while(start < end)
		{
			if(s.at(start) != s.at(end))
				return false;
			start++;
			end--;
		}
		return true;
	}
	void findPalin(string s, int start, vector<string> v)
	{
		if(start == s.length())
		{
			all.push_back(v);
			return;
		}
		int len = s.length();
		for(int i = start; i < len; i++)
		{
			if(isPalin(s, start, i))
			{
				v.push_back(s.substr(start,i - start + 1));
				findPalin(s, i+1, v);
				v.pop_back();
			}
		}
	}
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		all.clear();
        vector<string> v;
		findPalin(s, 0, v);
		return all;
    }
};