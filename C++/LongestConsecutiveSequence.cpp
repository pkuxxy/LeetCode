#include <iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;
class Solution {
public:
	int getCount(unordered_set<int>& s, int n, bool asc)
	{
		int count = 0;
		while(s.find(n) != s.end())
		{
			count++;
			s.erase(s.find(n));
			n = asc ? n+1:n-1;
		}
		return count;
	}
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len = num.size();
		if(!len)
			return 0;
		unordered_set<int> s;
		int maxCount = 0;
		for(int i = 0; i < len; i++)
		{
			s.insert(num[i]);
		}
		for(int i = 0; i < len ;i++)
		{
			maxCount = max(maxCount, getCount(s, num[i], false)+getCount(s,num[i]+1,true));
		}
		return maxCount;
    }
};
int main()
{
	vector<int> num;
	int a[7] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
	for(int i = 0; i < 7; i++)
	{
		num.push_back(a[i]);
	}
	Solution sol;
	cout<<sol.longestConsecutive(num);
	getchar();
}