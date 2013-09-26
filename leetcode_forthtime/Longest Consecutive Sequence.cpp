#include<set>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getMaxlen(set<int>&s, int num, bool desc)
    {
        int count = 0;
        set<int>::iterator iter = s.find(num);
        while(iter != s.end())
        {
            count++;
            num = (desc ? (num-1):(num+1));
            s.erase(iter);
            iter = s.find(num);
        }
        return count;
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if(!len)
            return 0;
        set<int> s;
        for(int i = 0; i < len; i++)
        {
            if(s.find(num[i]) == s.end())
                s.insert(num[i]);
        }
        int maxlen = 0;
        for(int i = 0; i < len; i++)
        {
            if(s.find(num[i]) != s.end())
            {
                maxlen = max(maxlen, getMaxlen(s, num[i], true)+getMaxlen(s, num[i]+1, false));
            }
        }
		return maxlen;
    }
};
int main() {
	int a[] = {100, 4, 200, 1, 3, 2};
	vector<int> num(a, a+6);
	Solution sol;
	cout<<sol.longestConsecutive(num);
	getchar();
	return 0;
}