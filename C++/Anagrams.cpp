#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        map<string, vector<string>> vm;
		for(int i = 0; i < strs.size(); i++)
		{
			string cur = strs[i];
			sort(cur.begin(), cur.end());
			map<string, vector<string>>::iterator iter = vm.find(cur);
			if(iter != vm.end())
			{
				iter->second.push_back(strs[i]);
			}
			else
			{
				vector<string> list;
				list.push_back(strs[i]);
				vm[cur] = list;
			}	
		}
		
		for(map<string, vector<string>>::iterator iter = vm.begin(); iter != vm.end(); iter++)
		{
			vector<string> list = iter->second;
			if(list.size() <= 1)
				continue;
			for(int i = 0; i < list.size(); i++)
			{
				ret.push_back(list[i]);
			}
		}
		return ret;
    }
};