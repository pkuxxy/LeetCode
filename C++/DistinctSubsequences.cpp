#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
		int lens = S.size();
		if(!lens)
			return 0;
		int lent = T.size();
		vector<vector<int>> d(lens);
		for(int i = 0; i < lens ;i++)
		{
			d[i] = vector<int>(lent,0);
		}
		if(S[0] == T[0])
			d[0][0] = 1;
		else
			d[0][0] = 0;
		for(int i = 1; i < lens; i++)
		{
			if(S[i] == T[0])
				d[i][0] = d[i-1][0]+1;
			else
				d[i][0] = d[i-1][0];
		}
		for(int i = 1; i < lens; i++)
		{
			for(int j = 1; j < lent; j++)
			{
				if(S[i] == T[j])
					d[i][j] = d[i-1][j] + d[i-1][j-1];
				else
					d[i][j] = d[i-1][j];
			}
		}
		return d[lens-1][lent-1];
    }
};