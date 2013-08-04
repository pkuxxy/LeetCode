#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len = matrix.size();
		if(!len)
			return;
		for(int level = 0; level <= len/2; level++)
		{		
			for(int i = level; i < len - level-1; i++)
			{
				int tmp = matrix[level][i];
				matrix[level][i] = matrix[len-i-1][level];
				matrix[len-i-1][level] = matrix[len-level-1][len-i-1];
				matrix[len-level-1][len-i-1] = matrix[i][len-level-1];
				matrix[i][len-level-1] = tmp;
			}
		}
    }
};