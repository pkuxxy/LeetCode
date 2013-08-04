#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1 = word1.size();
		int len2 = word2.size();
		if(!len1 || !len2)
			return len1+len2;
		vector<vector<int>> d(len1+1);
		for(int i = 0; i < len1 + 1; i++)
		{
			d[i] = vector<int>(len2+1);
		}
		for(int i = 0; i < len1+1; i++)
		{
			d[i][0] = i;
		}
		for(int i = 0; i < len2 + 1; i++)
		{
			d[0][i] = i;
		}
		for(int i = 1; i < len1+1; i++)
		{
			for(int j = 1; j < len2+1; j++)
			{
				d[i][j] = min(d[i-1][j-1], min(d[i-1][j], d[i][j-1])) + 1;
				if(word1[i-1] == word2[j-1])
					d[i][j] = min(d[i-1][j-1],d[i][j]);
			}
		}
		return d[len1][len2];
    }
};