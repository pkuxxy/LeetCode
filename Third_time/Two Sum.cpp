#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ret;
		if(numbers.size() < 2)
			return ret;
        map<int, int> mapping;
		for(int i = 0; i < numbers.size(); i++)
		{
			map<int, int>::iterator iter = mapping.find(target - numbers[i]);
			if(iter != mapping.end())
			{
				ret.push_back(min(i+1, iter->second));
				ret.push_back(max(i+1, iter->second));
				return ret;
			}
			mapping.insert(pair<int, int>(numbers[i], i+1));
		}
		return ret;
    }
};