#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	//const static int INT_MX = (1<<31)-1;
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1 = S.size();
		int len2 = T.size();
		vector<int> count1(256, 0);
		vector<int> count2(256, 0);
		for(int i = 0; i < len2; i++)
		{
			count1[T[i]]++;
			count2[T[i]]++;
		}
		int start = 0;
		int minStart = 0;
		int minSize = INT_MAX;
		int count = len2;
		for(int i = 0; i < len1; i++)
		{
			if(count2[S[i]] > 0)
			{
				count1[S[i]]--;
				if(count1[S[i]] >= 0)
					count--;
			}
			else
				continue;
			if(count == 0)
			{
				while(true)
				{
					if(count2[S[start]] > 0)
					{
						if(count1[S[start]] < 0)
							count1[S[start]]++;
						else
							break;
					}
					start++;
				}
				int size = i - start +1;
				if(minSize > size)
				{
					minStart = start;
					minSize = size;
				}
			}
		}
		if(minSize == INT_MAX)
			return "";
		return S.substr(minStart,minSize);
    }
};
int main()
{
	string s = "abcea";
	string t = "abc";
	Solution sol;
	cout<<sol.minWindow(s,t);
	getchar();
}