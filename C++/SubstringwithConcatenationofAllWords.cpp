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
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
		if(S.size() == 0 || L.size() == 0 || S.size() < L.size()*L[0].size())
			return ret;
		map<string, int> wordCountMap;
		for(int i = 0; i < L.size(); i++)
		{
			map<string, int>::iterator iter = wordCountMap.find(L[i]);
			if(iter == wordCountMap.end())
			{
				wordCountMap[L[i]] = 1;
			}
			else
				iter->second++;
				//wordCountMap[L[i]] += 1;
		}
		int wordLen = L[0].size();
		for(int i = 0; i + L.size()*wordLen <= S.size(); i++)
		{
			map<string, int> init = map<string, int>(wordCountMap);
			for(int j = 0; j < L.size(); j++)
			{
				string word = S.substr(i+j*wordLen, wordLen);
				map<string, int>::iterator iter = init.find(word);
				if(iter == init.end())
					break;
				iter->second--;
				if(iter->second == 0)
					init.erase(iter);
			}
			if(init.empty())
				ret.push_back(i);
		}
		return ret;
    }
};