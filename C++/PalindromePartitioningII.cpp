#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len = s.size();
		if(!len)
			return 0;
		vector<vector<bool>> b(len);
		for(int i = 0; i < len ;i++)
		{
			b[i] = vector<bool>(len,false);
		}
		for(int i = 0; i < len ;i++)
		{
			b[i][i] = true;
		}
		for(int i = 0; i < len-1; i++)
		{
			if(s[i] == s[i+1])
				b[i][i+1] = true;
		}
		for(int l = 3; l <= len; l++)
		{
			for(int i = 0; i <= len-l; i++)
			{
				int j = i + l - 1;
				if(s[i] == s[j] && b[i+1][j-1])
					b[i][j] = true;
			}
		}
		vector<int> d(len,0);
		for(int i = 0; i < len; i++)
		{
			if(b[0][i])
			{
				d[i] = 0;
				continue;
			}
			d[i] = (1<<31)-1;
			for(int j = 1; j <= i; j++)
			{
				if(b[j][i])
					d[i] = min(d[i],d[j-1] + 1);
			}
		}
		return d[len-1];
    }
};