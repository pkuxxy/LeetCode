#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int>> ret;
		if(num.size() < 4)
			return ret;
		sort(num.begin(), num.end());
		for(int i = 0; i < num.size()-3; i++)
		{
			if(i != 0 && num[i] == num[i-1])
				continue;
			for(int j = i + 1; j < num.size() - 2; j++)
			{
				if(j != (i + 1) && num[j] == num[j-1])
					continue;
				int k = j + 1;
				int m = num.size()-1;
				while(k < m)
				{
					if(k != (j+1) && num[k] == num[k-1])
					{
						k++;
						continue;
					}
					if(m != (num.size()-1) && num[m] == num[m+1])
					{
						m--;
						continue;
					}
					int sum = num[i] + num[j] + num[k] + num[m];
					if(sum == target)
					{
						vector<int> list;
						list.push_back(num[i]);
						list.push_back(num[j]);
						list.push_back(num[k]);
						list.push_back(num[m]);
						ret.push_back(list);
						k++;
					}
					else if(sum < target)
						k++;
					else if(sum > target)
						m--;
				}
			}
		}
		return ret;
	}
};