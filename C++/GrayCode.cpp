#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
		int size = (1<<n)-1;
		for(int i = 0; i <= size; i++)
		{
			ret.push_back(i^(i>>1));
		}
		return ret;
    }
};